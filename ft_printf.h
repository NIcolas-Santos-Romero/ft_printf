/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:38:40 by nicsanto          #+#    #+#             */
/*   Updated: 2026/06/28 19:38:41 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_print_char(int c);
int			ft_print_str(char *str);
int			ft_print_nbr(int n);
int			ft_print_unsigned(unsigned int n);
int			ft_print_hex(unsigned long n, char format);
int			ft_printf(const char *str, ...);

#endif
