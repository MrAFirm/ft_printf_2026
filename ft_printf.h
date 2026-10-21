/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:46:38 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/21 16:39:52 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"


# include <stdio.h>


typedef struct  s_count
{
	int	char_count;
} t_count;

int	ft_printf(const char *arr, ...);
int	p_address(va_list arg, char *hex);
int	h_x(va_list arg, char *hex);
int	h_X(va_list arg, char *hex);
int	di(va_list arg);

#endif