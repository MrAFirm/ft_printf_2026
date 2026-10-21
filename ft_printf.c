/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likhye-y <likhye-y@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:46:26 by likhye-y          #+#    #+#             */
/*   Updated: 2026/10/21 17:05:49 by likhye-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_choices(const char *arr, va_list arg, t_count *count);
static int	h_format(const char *arr, va_list arg, t_count *count, size_t i);
static int	e_cases(const char *arr, t_count *count, size_t i);

int	ft_printf(const char *arr, ...)
{
	va_list	args;
	t_count	count;

	va_start(args, arr);
	format_choices(arr, args, &count);
	va_end(args);
	return (count.char_count);
}

static int	format_choices(const char *arr, va_list arg, t_count *count)
{
	size_t	i;

	i = 0;
	count->char_count = 0;
	while (arr[i] != '\0')
	{
		if (ft_strncmp(&arr[i], "%", 1) == 0)
		{
			i++;
			count->char_count = h_format(arr, arg, count, i);
		}
		else
			count->char_count = e_cases(arr, count, i);
		i++;
	}
	return (count->char_count);
}

static int	h_format(const char *arr, va_list arg, t_count *count, size_t i)
{
	char	*hex;

	hex = malloc(sizeof(char) * 17);
	if (!hex)
		return (-1);
	if (ft_strncmp(&arr[i], "c", 1) == 0)
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		count->char_count++;
	}
	else if (ft_strncmp(&arr[i], "s", 1) == 0)
		count->char_count += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (ft_strncmp(&arr[i], "p", 1) == 0)
		count->char_count += p_address(arg, hex);
	else if (ft_strncmp(&arr[i], "x", 1) == 0)
		count->char_count += h_x(arg, hex);
	else if (ft_strncmp(&arr[i], "X", 1) == 0)
		count->char_count += h_X(arg, hex);
	else if (ft_strncmp(&arr[i], "d", 1) == 0)
		count->char_count += di(arg);
	else if (ft_strncmp(&arr[i], "i", 1) == 0)
		count->char_count += di(arg);
	else if (ft_strncmp(&arr[i], "%", 1) == 0)
	{
		ft_putchar_fd('%', 1);
		count->char_count++;
	}
	return (count->char_count);
}

static int	e_cases(const char *arr, t_count *count, size_t i)
{
	if (ft_strncmp(&arr[i], "\n", 1) == 0)
	{
		ft_putchar_fd('\n', 1);
		count->char_count++;
	}
	else if (ft_strncmp(&arr[i], " ", 1) == 0)
	{
		ft_putchar_fd(' ', 1);
		count->char_count++;
	}
	else
	{
		ft_putchar_fd(arr[i], 1);
		count->char_count++;
	}
	return (count->char_count);
}

/*
int main(void)
{
	ft_printf("ft_printf: %d\n", ft_printf("c: %c ", 'c'));
	printf("printf: %d\n", printf("c: %c ", 'c'));
	ft_printf("ft_printf: %d\n", ft_printf("s: %s ", "Hello"));
	printf("printf: %d\n", printf("s: %s ", "Hello"));
	int		value = 3;
	ft_printf("ft_printf: %d\n", ft_printf("d: %d ", value));
	printf("printf: %d\n", printf("d: %d ", value));
	ft_printf("ft_printf: %d\n", ft_printf("i: %i ", value));
	printf("printf: %d\n", printf("i: %i ", value));
	ft_printf("ft_printf: %d\n", ft_printf("x: %x ", value));
	printf("printf: %d\n", printf("x: %x ", value));
	ft_printf("ft_printf: %d\n", ft_printf("X: %X ", value));
	printf("printf: %d\n", printf("X: %X ", value));
	ft_printf("ft_printf: %d\n", ft_printf("p: %p ", &value));
	printf("printf: %d\n", printf("p: %p ", &value));
	ft_printf("ft_printf: %d\n", ft_printf("%%%%"));
	printf("printf: %d\n", printf("%%%%"));
}
*/
