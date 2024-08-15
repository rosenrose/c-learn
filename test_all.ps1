foreach ($dir in ls -Directory) {
    echo $dir.BaseName
    clang -std=c89 -W -Wall -pedantic-errors "$dir/*.c" -o "$dir/a.exe"
    &"$dir/a"
    echo ""
}
