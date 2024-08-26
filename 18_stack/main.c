#include <stdio.h>
#include <assert.h>

enum
{
    MAX_CNT = 8
};
enum
{
    INVALID_IDX = -1
};

int s_arr[MAX_CNT];
size_t s_arr_cnt = 0;

void print_arr(void);
void push(const int num);
int is_empty(void);
int pop(void);
size_t find_idx(const int num);

int main(void)
{
    push(8);
    push(4);
    push(2);
    push(0);
    print_arr();

    printf("pop: %d\n", pop());
    print_arr();

    printf("index of 4: %llu\n", find_idx(4));
    printf("index of 1: %llu\n", find_idx(1));

    return 0;
}

void print_arr(void)
{
    size_t i;

    for (i = 0; i < s_arr_cnt; i++)
    {
        printf("%d ", s_arr[i]);
    }

    putchar('\n');
}

void push(const int num)
{
    assert(s_arr_cnt < MAX_CNT);

    s_arr[s_arr_cnt] = num;
    s_arr_cnt++;
}

int is_empty(void)
{
    return s_arr_cnt == 0;
}

int pop(void)
{
    assert(!is_empty());

    s_arr_cnt--;

    return s_arr[s_arr_cnt];
}

size_t find_idx(const int num)
{
    size_t i;

    for (i = 0; i < s_arr_cnt; i++)
    {
        if (s_arr[i] == num)
        {
            return i;
        }
    }

    return INVALID_IDX;
}
