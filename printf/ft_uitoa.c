/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:35:23 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 13:06:14 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
//lengh of the number
int	ft_len_num(unsigned	int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

//unsigned int to ascci
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len_num(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		--len;
		num[len] = n % 10 + 48;
		n = n / 10;
	}
	return (num);
}
