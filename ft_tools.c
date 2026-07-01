/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:38:41 by nicsanto          #+#    #+#             */
/*   Updated: 2026/07/01 16:13:20 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write (1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		i = write(1, "(null)", 6);
		if (i == -1)
			return (i);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	int		len;
	long	num;
	int		tmp;

	len = 0;
	num = n;
	if (num < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		num = -num;
	}
	if (num > 9)
	{
		tmp = ft_print_nbr(num / 10);
		if (tmp == -1)
			return (tmp);
		len += tmp;
	}
	tmp = ft_print_char((num % 10) + '0');
	if (tmp == -1)
		return (tmp);
	len += tmp;
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n > 9)
	{
		tmp = ft_print_unsigned(n / 10);
		if (tmp == -1)
			return (tmp);
		len += tmp;
	}
	if (ft_print_char((n % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_print_hex(unsigned long n, char format)
{
	int		len;
	char	*base;
	int		tmp;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		tmp = ft_print_hex(n / 16, format);
		if (tmp == -1)
			return (tmp);
		len += tmp;
	}
	tmp = ft_print_char(base[n % 16]);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
