/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:46:38 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/19 17:12:28 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

# include <stdio.h>

// typedef struct  s_

int	ft_printf(const char *arr, ...);
void    p_address(va_list arg);
void    h_x(va_list arg);
void    h_X(va_list arg);

#endif