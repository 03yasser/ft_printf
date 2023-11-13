#include "ft_printf.h"

int add (int count, ...)
{
    int x = 0;
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++)
    {
        x+= va_arg(args, int);
    }
    return (x);
}
int main ()
{
    printf("%d\n", add(4,1,1,1,1));
}