/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:38:48 by nicsanto          #+#    #+#             */
/*   Updated: 2026/06/28 19:38:49 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len = ft_print_str("(nil)");
		return (len);
	}
	len += ft_print_str("0x");
	len += ft_print_hex((unsigned long)ptr, 'x');
	return (len);
}

static int	ft_con(const char type, va_list args)
{
	if (type == '%')
		return (ft_print_char('%'));
	else if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), type));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_con(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
