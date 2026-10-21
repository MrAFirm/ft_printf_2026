/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:15:03 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/21 16:24:13 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	h_x(va_list arg, char *hex)
{
	unsigned long	buf;
	unsigned long	count;
	int				chr_count;

	hex = "0123456789abcdef";
	buf = va_arg(arg, int);
	count = 0;
	chr_count = 0;
	while (buf >= 16)
	{
		count += buf / 16;
		ft_putchar_fd(hex[buf % 16], 1);
		buf -= count;
		chr_count++;
	}
	if (buf < 16)
		ft_putchar_fd(hex[buf % 16], 1);
	chr_count++;
	return (chr_count);
}

int	h_X(va_list arg, char *hex)
{
	unsigned long	buf;
	unsigned long	count;
	int				chr_count;

	hex = "0123456789ABCDEF";
	buf = va_arg(arg, int);
	count = 0;
	chr_count = 0;
	while (buf >= 16)
	{
		count += buf / 16;
		ft_putchar_fd(hex[buf % 16], 1);
		buf -= count;
		chr_count++;
	}
	if (buf < 16)
		ft_putchar_fd(hex[buf % 16], 1);
	chr_count++;
	return (chr_count);
}
