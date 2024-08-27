#include <stdio.h>
#include <limits.h>

#define TRUE (1)
#define FALSE (0)
#define MOD (23)

int s_arr[MOD];

void init_arr(void);
int has_value(const int val);
int add(const int val);

int main(void)
{
    init_arr();
    add(703);
    add(793);
    add(724);
    add(441);
    add(219);
    add(1);
    add(81);
    add(546);
    add(777);
    add(747);

    {
        size_t i;

        for (i = 0; i < MOD; i++)
        {
            if (s_arr[i] == INT_MIN)
            {
                printf("%c ", '-');
            }
            else
            {
                printf("%d ", s_arr[i]);
            }
        }
    }

    return 0;
}

void init_arr(void)
{
    size_t i;

    for (i = 0; i < MOD; i++)
    {
        s_arr[i] = INT_MIN;
    }
}

int has_value(const int val)
{
    int start_idx = val % MOD;
    int i;

    if (start_idx < 0)
    {
        start_idx += MOD;
    }

    i = start_idx;

    do
    {
        if (s_arr[i] == val)
        {
            return TRUE;
        }
        else if (s_arr[i] == INT_MIN) /* 이 분기의 전제 조건은 중간에 삭제되는 요소가 없어야 함 */
        {
            return FALSE;
        }

        i = (i + 1) % MOD;

    } while (i != start_idx);

    return FALSE;
}

int add(const int val)
{
    int start_idx = val % MOD;
    int i;

    if (start_idx < 0)
    {
        start_idx += MOD;
    }

    i = start_idx;

    do
    {
        if (s_arr[i] == INT_MIN || s_arr[i] == val)
        {
            s_arr[i] = val;

            return TRUE;
        }

        i = (i + 1) % MOD;

    } while (i != start_idx);

    return FALSE;
}
