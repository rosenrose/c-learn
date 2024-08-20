#include <stdio.h>
#include "monster_repo.h"

int main(void)
{
    add_monster();
    add_monster();
    printf("%d\n", g_mob_count);
    return 0;
}
