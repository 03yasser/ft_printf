# include "ft_printf.h"

int main()
{
    char c = 's';
    printf ("\n%zd\n", write (-350, &c, 1));
}