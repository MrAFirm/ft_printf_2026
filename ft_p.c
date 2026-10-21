/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:58 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/21 16:40:33 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_ptr(uintptr_t value, char *hex);
static char	*fill_buf(uintptr_t value, char *hex, int i, char *buf);

int    p_address(va_list arg, char *hex)
{
	uintptr_t	value;
	void		*ptr;
	int			count;

	ptr = va_arg(arg, void *);
	value = (uintptr_t)ptr;
	if (value == 0)
	{
		ft_putstr_fd("0x0", 1);
		count = 4;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		count = 2 + hex_ptr(value, hex);
	}
	return (count);
}

static int	hex_ptr(uintptr_t value, char *hex)
{
	char	buf[13];
	int		i;
	int		chr_count;
	
	hex = "0123456789abcdef";
	i = 0;
	fill_buf(value, hex, i, buf);
	i = ft_strlen(buf);
	chr_count = i;
	while (i >= 0)
	{
		ft_putchar_fd(buf[i], 1);
		i--;
	}
	return (chr_count);
}

static char	*fill_buf(uintptr_t value, char *hex, int i, char *buf)
{
	while (value >= 16)
	{
		buf[i] = hex[value % 16];
		value = value / 16;
		i++;
	}
	if (value < 16)
	{
		buf[i] = hex[value % 16];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
