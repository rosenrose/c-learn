## 실행

`clang -std=c89 -W -Wall -pedantic-errors *.c && ./a`

## 전처리

`clang -std=c89 -W -Wall -pedantic-errors -E`

## 컴파일

`clang -std=c89 -W -Wall -pedantic-errors -S`

## 어셈블

`clang -std=c89 -W -Wall -pedantic-errors -c`

## 링크

`clang -std=c89 -W -Wall -pedantic-errors *.o`

## 정적 라이브러리 생성

`llvm-ar -r <.lib_output> <.o_inputs>`

## 정적 라이브러리와 함께 빌드

`clang -std=c89 -W -Wall -pedantic-errors -I <header_dir> -L <lib_dir> -l<lib_name> *.c`
