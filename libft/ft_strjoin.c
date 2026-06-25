/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanto <nicsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 00:07:10 by nicsanto          #+#    #+#             */
/*   Updated: 2026/06/18 18:58:46 by nicsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = ft_calloc(1, ((s1_len + s2_len) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, ((s1_len + s2_len) + 1));
	ft_strlcat(ptr, s2, ((s1_len + s2_len) + 1));
	return (ptr);
}
