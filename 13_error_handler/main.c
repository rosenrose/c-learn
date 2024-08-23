#include <stdio.h>
#include "error_handler.h"

#define TRUE (1)
#define FALSE (0)

void simple_stderr_print(const char *const msg);
int run(void);

int main(void)
{
    int is_success = run();

    register_err_handler(default_err_handler);
    is_success = run();

    register_err_handler(simple_stderr_print);
    is_success = run();

    return is_success ? 0 : 1;
}

int run(void)
{
    int numerator;
    int denominator;

    while (TRUE)
    {
        printf("Enter numerator and denominator: ");

        if (scanf_s("%d %d", &numerator, &denominator) == 2)
        {
            break;
        }
    }

    if (denominator == 0)
    {
        log_err("Cannot divide by zero");
        return FALSE;
    }

    printf("%d / %d = %.2lf\n", numerator, denominator, numerator / (double)denominator);

    return TRUE;
}

void simple_stderr_print(const char *const msg)
{
    fputs(msg, stderr);
}
