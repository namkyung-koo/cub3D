/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:54:58 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/22 22:11:00 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (print_error("Negative numbers are not allowed.", -1, NULL));
		str++;
	}
	if (*str == '\0')
		return (print_error("There are invaild arguments.", -1, NULL));
	res = 0;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (print_error("There are invaild arguments.", -1, NULL));
	if (res > 255)
		return (print_error("RGB must be less than 256.", -1, NULL));
	return (res);
}
