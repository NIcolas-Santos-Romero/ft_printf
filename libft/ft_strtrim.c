/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:24:23 by nicsanto          #+#    #+#             */
/*   Updated: 2026/06/18 18:59:06 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_i;
	size_t	str_f;

	str_i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	str_f = ft_strlen(s1);
	while (s1[str_i] != '\0' && ft_strchr(set, s1[str_i]) != NULL)
		str_i++;
	while (str_f > str_i && ft_strchr(set, s1[str_f - 1]) != NULL )
		str_f--;
	return (ft_substr(s1, str_i, str_f - str_i));
}
