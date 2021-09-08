#include <stdarg.h>
#include <stdio.h>

#include "om_string.h"

int OM_format(char* buffer, size_t len, char* fmt, ...)
{
    if (!fmt || !len)
        return 0;

    va_list va;
    va_start(va, fmt);
    int written = vsnprintf(buffer, len, fmt, va);
    va_end(va);
    return written;
}
