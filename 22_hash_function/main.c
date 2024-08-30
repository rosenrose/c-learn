#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "hash_function.h"

typedef struct
{
    unsigned char age;
    unsigned int id;
    char name[64];
} employee_t;

int main(void)
{
    employee_t person;
    size_t hash;
    float fval;

    hash = hash_int(10);
    printf("int    %llu\n", hash);

    hash = hash_int(-10);
    printf("int    %llu\n", hash);

    hash = hash_int('A');
    printf("char   %llu\n", hash);

    hash = hash_float(3.2);
    printf("float  %llu\n", hash);

    hash = hash_data("Kim Jangwook", strlen("Kim Jangwook"));
    printf("string %llu\n", hash);

    fval = 2.718;
    hash = hash_data(&fval, sizeof(float));
    printf("float  %llu\n", hash);

    memset(&person, 0, sizeof(employee_t)); /* 쓰레기 값이 해시에 영향을 주면 안 되므로 구조체 변수를 모두 0으로 초기화 */
    person.age = 21;
    person.id = 18274192;
    strcpy(person.name, "Pope Kim");

    hash = hash_data(&person, sizeof(employee_t));
    printf("struct %4llu\n", hash);

    return 0;
}
