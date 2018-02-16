echo '<pre class="f9 b9">'
(echo $ \(gcc-9 $@ 2\>\&1\) \| python -m json.tool \| pygmentize -l json ; ( ( gcc $@ -fdiagnostics-color=always 2>&1) | python -m json.tool | pygmentize -l json) ) \
    | ./invoke-ansi2html.sh \
    | sed 's|[ \t]*$||'
echo '</pre>'
