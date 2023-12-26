/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:37:34 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 13:09:50 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_print_hex(unsigned int num, const char format);
int					ft_print_ptr(unsigned long long ptr);
int					ft_print_u(unsigned int n);
char				*ft_uitoa(unsigned int n);
unsigned int		ft_yalda(va_list vl, const char format);
unsigned int		ft_print_str(char *str);
int					check_type(char ch);
unsigned int		ft_print_di(int d);
int					ft_printf(const char *format, ...);

#endif