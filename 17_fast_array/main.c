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
void insert_at(const size_t idx, const int num);
void insert_at_unorderd(const size_t idx, const int num);
size_t find_idx(const int num);
void remove_at(const size_t idx);
void remove_at_unordered(const size_t idx);

int main(void)
{
    insert_at(0, 0);
    insert_at(1, 1);
    insert_at(2, 2);
    insert_at(3, 3);
    insert_at(4, 4);
    insert_at(5, 5);
    print_arr();

    remove_at(1);
    print_arr();

    remove_at_unordered(1);
    print_arr();

    insert_at_unorderd(0, 9);
    print_arr();

    printf("index of 9: %llu\n", find_idx(9));
    printf("index of 10: %llu\n", find_idx(10));

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

void insert_at(const size_t idx, const int num)
{
    size_t i;

    assert(idx <= s_arr_cnt);
    assert(s_arr_cnt < MAX_CNT);

    for (i = s_arr_cnt; i > idx; i--)
    {
        s_arr[i] = s_arr[i - 1];
    }

    s_arr[idx] = num;
    s_arr_cnt++;
}

void insert_at_unorderd(const size_t idx, const int num)
{
    assert(idx <= s_arr_cnt);
    assert(s_arr_cnt < MAX_CNT);

    s_arr[s_arr_cnt] = s_arr[idx];
    s_arr[idx] = num;
    s_arr_cnt++;
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

void remove_at(const size_t idx)
{
    size_t i;

    assert(idx < s_arr_cnt);

    s_arr_cnt--;

    for (i = idx; i < s_arr_cnt; i++)
    {
        s_arr[i] = s_arr[i + 1];
    }
}

void remove_at_unordered(const size_t idx)
{
    assert(idx < s_arr_cnt);

    s_arr_cnt--;
    s_arr[idx] = s_arr[s_arr_cnt];
}
