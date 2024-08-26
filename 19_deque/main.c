#include <stdio.h>
#include <assert.h>

enum
{
    MAX_CNT = 8,
    ARR_LEN = MAX_CNT + 1
};
enum
{
    INVALID_IDX = -1
};

int s_arr[ARR_LEN];
size_t s_arr_cnt = 0;
size_t s_front = 0;
size_t s_back = 0;

void print_arr(void);
void push_back(const int num);
void push_front(const int num);
int is_empty(void);
int pop_back(void);
int pop_front(void);
size_t find_idx(const int num);

int main(void)
{
    push_back(10);
    push_back(20);
    push_back(30);
    push_back(40);
    push_front(50);
    push_front(60);
    push_front(70);
    push_front(80);
    print_arr();

    printf("pop front: %d\n", pop_front());
    printf("pop back: %d\n", pop_back());
    printf("pop back: %d\n", pop_back());
    printf("pop front: %d\n", pop_front());
    print_arr();

    printf("index of 60: %llu\n", find_idx(60));
    printf("index of 50: %llu\n", find_idx(50));
    printf("index of 10: %llu\n", find_idx(10));
    printf("index of 20: %llu\n", find_idx(20));
    printf("index of 0: %llu\n", find_idx(0));

    return 0;
}

void print_arr(void)
{
    size_t i;

    for (i = s_front; i != s_back; i = (i + 1) % ARR_LEN)
    {
        printf("%d ", s_arr[i]);
    }

    putchar('\n');
}

void push_back(const int num)
{
    assert(s_arr_cnt < MAX_CNT);

    s_arr[s_back] = num;
    s_back = (s_back + 1) % ARR_LEN;
    s_arr_cnt++;
}

void push_front(const int num)
{
    assert(s_arr_cnt < MAX_CNT);

    s_front = (s_front + MAX_CNT) % ARR_LEN;
    s_arr[s_front] = num;
    s_arr_cnt++;
}

int is_empty(void)
{
    return s_arr_cnt == 0;
}

int pop_back(void)
{
    assert(s_arr_cnt > 0);

    s_back = (s_back + MAX_CNT) % ARR_LEN;
    s_arr_cnt--;

    return s_arr[s_back];
}

int pop_front(void)
{
    int ret;

    assert(s_arr_cnt > 0);

    ret = s_arr[s_front];
    s_front = (s_front + 1) % ARR_LEN;
    s_arr_cnt--;

    return ret;
}

size_t find_idx(const int num)
{
    size_t i;
    size_t ret = 0;

    for (i = s_front; i != s_back; i = (i + 1) % ARR_LEN)
    {
        if (s_arr[i] == num)
        {
            return ret;
        }

        ret++;
    }

    return INVALID_IDX;
}
