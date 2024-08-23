#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}

/*  인자: int, void (*)(int)
    반환형: void (*)(int) */
void (*bsd_signal(int a, void (*ptr)(int)))(int)
{
    return ptr;
}

int main(void)
{

    int ints[2] = {1, 2};
    int(*ptr_to_twoElementArray_of_int)[2] = &ints;

    int (*func_ptrs[4])(int, int) = {add, sub, mul, div};
    int (*(*ptr_to_fourElementArray_of_func_ptr)[4])(int, int) = &func_ptrs;

    void (*(*func_ptr)(int, void (*)(int)))(int) = bsd_signal;

    printf("%lld\n", (char *)(ptr_to_twoElementArray_of_int + 1) - (char *)ptr_to_twoElementArray_of_int);
    printf("%lld\n", (char *)(ptr_to_fourElementArray_of_func_ptr + 1) - (char *)ptr_to_fourElementArray_of_func_ptr);

    return 0;
}
