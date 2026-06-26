#include "ft_printf.h"


static int ft_con(const char type, va_list)
{

}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (NULL);
	va_start(args, str);
	while (str[i] != "\0")
	{
		if (str[i] == "%")
		i += ft_con(str[i + 1], args);
	}


	return (i);
}
