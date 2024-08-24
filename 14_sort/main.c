#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "userdata.h"
#include "user_sorter.h"

enum
{
    NUM_USERS = 7
};

void print_users(const userdata_t users[])
{
    size_t i;

    for (i = 0; i < NUM_USERS; i++)
    {
        printf("age: %03d, id: %5d, gender: %d\n",
               users[i].age, users[i].id, users[i].gender);
    }
}
void print_radix_users(const radix_userdata_t radix_users[])
{
    size_t i;

    for (i = 0; i < NUM_USERS; i++)
    {
        printf("age: %03d, id: %5d, gender: %d\n",
               radix_users[i].user.age, radix_users[i].user.id, radix_users[i].user.gender);
    }
}

int main(void)
{
    userdata_t users[NUM_USERS];
    radix_userdata_t radix_users[NUM_USERS];
    size_t i = 0;

    users[i].id = 482;
    users[i].gender = GENDER_FEMALE;
    users[i++].age = 102;

    users[i].id = 510;
    users[i].gender = GENDER_MALE;
    users[i++].age = 22;

    users[i].id = 32;
    users[i].gender = GENDER_NONE;
    users[i++].age = 1;

    users[i].id = 221;
    users[i].gender = GENDER_FEMALE;
    users[i++].age = 38;

    users[i].id = 15;
    users[i].gender = GENDER_FEMALE;
    users[i++].age = 22;

    users[i].id = 333;
    users[i].gender = GENDER_MALE;
    users[i++].age = 1;

    users[i].id = 1024;
    users[i].gender = GENDER_NONE;
    users[i++].age = 52;

    assert(i == NUM_USERS);

    for (i = 0; i < NUM_USERS; i++)
    {
        radix_users[i].user = users[i];
    }

    puts("Sort by age then id");
    qsort(users, NUM_USERS, sizeof(userdata_t), cmp_age_id);
    print_users(users);

    puts("\nSort by age(desc) then gender");
    qsort(users, NUM_USERS, sizeof(userdata_t), cmp_age_desc_gender);
    print_users(users);

    /* Radix Sort */
    puts("\n\nRadix Sort by age then id");

    for (i = 0; i < NUM_USERS; i++)
    {
        unsigned char age = radix_users[i].user.age;
        unsigned short id = radix_users[i].user.id;

        radix_users[i].sort_key = (age << 16) | id; /* 상위 16비트는 나이, 하위 16비트는 아이디 */
    }

    qsort(radix_users, NUM_USERS, sizeof(radix_userdata_t), cmp_sort_key);
    print_radix_users(radix_users);

    puts("\nRadix Sort by age(desc) then gender");
    assert(GENDER_NONE < (1 << 2)); /* GENDER_NONE이 마지막 멤버라는 전제 */

    for (i = 0; i < NUM_USERS; i++)
    {
        unsigned char age_inv = UCHAR_MAX - radix_users[i].user.age;
        unsigned short gender = radix_users[i].user.gender;

        radix_users[i].sort_key = (age_inv << 2) | gender;
        /* gender_t는 3개의 값만 있으므로 2비트만으로 표현 가능
        그러나 열거형에 또 다른 종류를 추가해놓고 위 코드를 수정하지 않을 수 있으므로 assert 사용 */
    }

    qsort(radix_users, NUM_USERS, sizeof(radix_userdata_t), cmp_sort_key);
    print_radix_users(radix_users);

    return 0;
}
