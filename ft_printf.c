/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:46:26 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/19 17:14:50 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_choices(const char *arr, va_list arg);

int	ft_printf(const char *arr, ...)
{
	va_list	args;

	va_start(args, arr);
	format_choices(arr, args);
	va_end(args);
	return (1);
}

static void	format_choices(const char *arr, va_list arg)
{
	size_t	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (ft_strncmp(&arr[i], "%", 1) == 0)
		{
			i++;
			if (ft_strncmp(&arr[i], "c", 1) == 0)
				ft_putchar_fd(va_arg(arg, int), 1);
			else if (ft_strncmp(&arr[i], "s", 1) == 0)
				ft_putstr_fd(va_arg(arg, char *), 1);
			else if (ft_strncmp(&arr[i], "p", 1) == 0)
				p_address(arg);
			else if (ft_strncmp(&arr[i], "x", 1) == 0)
				h_x(arg);
			else if (ft_strncmp(&arr[i], "X", 1) == 0)
				h_X(arg);
		}
		else if (ft_strncmp(&arr[i], "\n", 1) == 0)
			ft_putchar_fd('\n', 1);
		i++;
	}
}


int main(void)
{
	// char	chr = 't';
	// ft_printf("%c\n", chr);
	
	// char	*str = "Hello World!";
	// ft_printf("%s\n\n%c", str, chr);

	// char	pointer = 'i';
	// ft_printf("%p\n", pointer);

	int		value = 1;
	ft_printf("%x\n", value);
	ft_printf("%X\n", value);
	int test = ft_printf("%p\n", &value);
	ft_printf("%d\n", test);
	printf("%d\n", printf("%p\n", &value));

	// printf("%X", -15);
}

