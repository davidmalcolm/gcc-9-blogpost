echo '<pre class="f9 b9">'
GCC_PATH=/home/david/coding/gcc-python/gcc-svn-8/install/bin
(echo $ g++-8 $@ ; PATH=$GCC_PATH:$PATH g++ $@ -fdiagnostics-color=always 2>&1) \
    | ./invoke-ansi2html.sh \
    | sed 's|[ \t]*$||'
echo '</pre>'
