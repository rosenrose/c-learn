#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "simpleio.h"

static void print_int(unsigned int val)
{
    unsigned int pow = 1;

    while (pow <= val / 10)
    {
        pow *= 10;
    }

    for (; pow > 0; pow /= 10)
    {
        unsigned int digit = val / pow;
        val -= digit * pow;

        putchar(digit + '0');
    }
}

void printf_simple(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    {
        for (; *format != '\0'; format++)
        {
            unsigned int val;
            const char *str;

            switch (*format)
            {
            case 's':
                str = va_arg(ap, const char *);

                for (; *str != '\0'; str++)
                {
                    putchar(*str);
                }
                break;
            case 'c':
                val = va_arg(ap, unsigned int);
                putchar(val);
                break;
            case 'd':
                val = va_arg(ap, unsigned int);
                print_int(val);
                break;

            default:
                putchar(*format);
                break;
            }
        }
    }
    va_end(ap);
}
