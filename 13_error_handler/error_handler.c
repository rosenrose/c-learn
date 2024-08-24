#include <stdio.h>
#include <time.h>
#include "error_handler.h"

static void (*s_handler)(const char *const) = NULL;

void register_err_handler(void (*const handler)(const char *const msg))
{
    s_handler = handler;
}

void log_err(const char *const msg)
{
    if (s_handler == NULL)
    {
        return;
    }

    s_handler(msg);
}

void default_err_handler(const char *const msg)
{
    const time_t now = time(NULL); /* 현재 시간 */
    struct tm local;

    localtime_s(&local, &now);
    fprintf(stderr, "[%02d:%02d:%02d] %s\n",
            local.tm_hour, local.tm_min, local.tm_sec,
            msg);
}
