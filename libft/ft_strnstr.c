/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:23:21 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:16:51 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return (1);
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
	j = 0;
		while (i + j < len && haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (j == needle_len)
			return (0);
		i++;
	}
	return (1);
}
