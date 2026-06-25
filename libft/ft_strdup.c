/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:04:25 by nicsanto          #+#    #+#             */
/*   Updated: 2026/06/18 18:58:39 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	str_len;

	str_len = ft_strlen(s);
	ptr = malloc(str_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, (str_len + 1));
	return (ptr);
}
