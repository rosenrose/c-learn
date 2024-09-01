foreach ($dir in ls -Directory "??_*") {
    cd $dir
    echo $dir.BaseName
    clang -std=c89 -W -Wall -pedantic-errors *.c \
    ./a
    echo ""
}
