$name = $args[0]
$def = "$($name.ToUpper())_H"
mkdir $name

@"
#ifndef $def
#define $def

#endif /* $def */
"@ > $name/$name.h

@"
#include "$name.h"
"@ > $name/$name.c

@"
#include "$name.h"

int main(void)
{
    return 0;
}
"@ > $name/main.c
