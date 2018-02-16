import re
import subprocess
import sys

from pygments import highlight
from pygments.lexers import guess_lexer_for_filename
from pygments.formatters import HtmlFormatter

import premailer # pip install premailer

class Writer:
    def __init__(self):
        cmd = ['/home/david/coding-3/gcc-git-bugfixing/src/ansi2html.sh',
               '--bg=dark', '--palette=solarized-xterm', '--css-only']
        self.css = subprocess.check_output(cmd,
                                           stderr=subprocess.PIPE)

    def log(self, msg):
        sys.stderr.write('%s\n' % msg)

    def apply_css(self, text):
        """Bake CSS rules into text"""
        p = premailer.Premailer(html=text, css_text=self.css,
                                remove_classes=True,
                                remove_unset_properties=True,
                                disable_leftover_css=True)
        out = p.transform()
        for tag in ['html', 'head', 'body']:
            out = out.replace('<%s>' % tag, '')
            out = out.replace('</%s>' % tag, '')
        # <span>s within a <pre> should also be monospace
        out = out.replace('<span style="',
                          '<span style="font-family: monospace; ')
        return out

    def write(self, text):
        sys.stdout.write(text.encode('utf-8'))

    def invoke_gcc(self, cmd, helper_script):
        self.log('invoke_gcc: %s' % (cmd, ))
        out = subprocess.check_output(['bash', helper_script, cmd],
                                      stderr=subprocess.PIPE)
        out = out.decode('utf-8')
        out = self.apply_css(out)
        assert 'class=' not in out
        self.write(out + '\n')

    def include_source(self, path):
        path = path.strip()
        self.log('invoke_source: %s' % path)
        with open(path) as f:
            code = f.read()
        lexer = guess_lexer_for_filename(path, code)
        self.write(highlight(code, lexer, HtmlFormatter(noclasses=True)))

    def handle_file(self, path):
        with open(path) as f:
            for line in f:
                m = re.match('INVOKE_GCC (.*)', line)
                if m:
                    self.invoke_gcc(m.group(1), './gcc-to-html.sh')
                    continue
                m = re.match('INVOKE_OLD_GCC (.*)', line)
                if m:
                    self.invoke_gcc(m.group(1), './old-gcc-to-html.sh')
                    continue
                m = re.match('INVOKE_GPP (.*)', line)
                if m:
                    self.invoke_gcc(m.group(1), './g++-to-html.sh')
                    continue
                m = re.match('INVOKE_OLD_GPP (.*)', line)
                if m:
                    self.invoke_gcc(m.group(1), './old-g++-to-html.sh')
                    continue
                m = re.match('INVOKE_GCC_JSON (.*)', line)
                if m:
                    self.invoke_gcc(m.group(1), './gcc-to-html-json.sh')
                    continue
                m = re.match('INCLUDE (.*)', line)
                if m:
                    self.handle_file(m.group(1))
                    continue
                m = re.match('INCLUDE_SOURCE (.*)', line)
                if m:
                    self.include_source(m.group(1))
                    continue
                self.write(line)

w = Writer()
w.handle_file(sys.argv[1])
