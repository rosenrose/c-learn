#include <stdio.h>
#include "adder.h"
#include "inline_math.h"
#include "static_inline_math.h"

int main(void)
{
    puts(__FILE__);
    printf("1 + 2 = %d\n", static_inline_add(1, 2));
    printf("addr of static_inline_add: %p\n", (void *)static_inline_add);
    /* 이 주소는 main.c와 adder.c에서 다름. 각 .c 파일마다 정적 함수가 만들어졌기 때문
    만약 인라인화가 안 됐다면 무의미하게 파일 크기가 2배로 늘어남 */

    printf("1 + 2 = %d\n", inline_add(1, 2));
    printf("addr of inline_add: %p\n", (void *)inline_add);
    /* 이 주소는 main.c와 adder.c에서 같음. inline_math.c에서 딱 한 번만 함수를 정의했기 때문 */

    putchar('\n');
    run_adder();

    return 0;
}
