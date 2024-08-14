#include <stdio.h>

void func(void)
{
    return;
}

int main(void)
{
    void (*a)(void) = func;
    unsigned char *p = (unsigned char *)&a;
    unsigned long i;
    char buffer[17] = {
        0,
    };
    int pos = 0;
    int bytes;
    char temp1, temp2;

    for (i = 0; i < sizeof(a); i++)
    {
        bytes = sprintf(buffer + pos, "%02x", p[i]);
        pos += bytes;
    }

    for (i = 0; i < 8; i += 2)
    {
        temp1 = buffer[i];
        temp2 = buffer[i + 1];
        buffer[i] = buffer[15 - (i + 1)];
        buffer[i + 1] = buffer[15 - i];
        buffer[15 - (i + 1)] = temp1;
        buffer[15 - i] = temp2;
    }

    printf("%s\n", buffer);
    printf("%016llx\n", func);

    return 0;
}
