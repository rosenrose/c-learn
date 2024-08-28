
#include <stdio.h>

/* (type, member) */
#define MONSTER_STRUCT                 \
    MONSTER_MEMBER(int, id)            \
    MONSTER_MEMBER(const char *, name) \
    MONSTER_MEMBER(int, hp)

typedef struct
{
#define MONSTER_MEMBER(type, member) type member;
    MONSTER_STRUCT
#undef MONSTER_MEMBER
} monster_t;

#define MONSTER_MEMBER(type, member)                  \
    type get_mob_##member(const monster_t *const mob) \
    {                                                 \
        return mob->member;                           \
    }

MONSTER_STRUCT

#undef MONSTER_MEMBER

int main(void)
{
    size_t i;
    monster_t mob;

/* id(int), name(const char*), hp(int) */
#define MONSTER_DATA                \
    MONSTER_ENTRY(0, "pope", 100)   \
    MONSTER_ENTRY(1, "big rat", 30) \
    MONSTER_ENTRY(2, "mama", 255)   \
    MONSTER_ENTRY(3, "dragon", 40000)

    const int ids[] = {
#define MONSTER_ENTRY(id, name, hp) id,
        MONSTER_DATA
#undef MONSTER_ENTRY
    };

    const char *const names[] = {
#define MONSTER_ENTRY(id, name, hp) name,
        MONSTER_DATA
#undef MONSTER_ENTRY
    };

    const int hps[] = {
#define MONSTER_ENTRY(id, name, hp) hp,
        MONSTER_DATA
#undef MONSTER_ENTRY
    };

    for (i = 0; i < sizeof(ids) / sizeof(int); i++)
    {
        printf("%3d %6d %s\n", ids[i], hps[i], names[i]);
    }

    mob.id = 99;
    mob.name = "haha";
    mob.hp = 3788;

    printf("%3d %6d %s\n", get_mob_id(&mob), get_mob_hp(&mob), get_mob_name(&mob));

    return 0;
}
