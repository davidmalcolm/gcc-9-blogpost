echo '<pre class="f9 b9">'
(echo $ gcc-9 $@ ; gcc $@ -fdiagnostics-color=always 2>&1) \
    | ./invoke-ansi2html.sh \
    | sed 's|[ \t]*$||'
echo '</pre>'
