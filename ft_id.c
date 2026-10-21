/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:31:58 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/21 16:38:53 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	di(va_list arg)
{
	int	result;
	int	count;
	int	res_count;

	result = va_arg(arg, int);
	res_count = result;
	count = 1;
	if (res_count < 0)
	{
		res_count *= -1;
		count++;
	}
	while (res_count >= 10)
	{
		res_count = res_count / 10;
		count++;
	}
	ft_putnbr_fd(result, 1);
	return (count);
}
