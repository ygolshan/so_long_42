/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:53:33 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:16:38 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!(str))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	output = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!output)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		output[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		output[i + j] = s2[j];
	output[i + j] = '\0';
	return (output);
}
