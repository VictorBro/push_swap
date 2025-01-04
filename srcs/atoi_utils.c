/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:37 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 19:19:49 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	atoi_helper(char *str, int *num, int minus)
{
	if (!ft_isdigit(*str))
		return (FALSE);
	if (*num > 0 && minus % 2 == 1)
		*num *= -1;
	if (*num < INT_MIN / 10 || (*num == INT_MIN / 10 && *str - '0' > 8))
		return (FALSE);
	if (*num > INT_MAX / 10 || (*num == INT_MAX / 10 && *str - '0' > 7))
		return (FALSE);
	if (minus % 2 == 1)
		*num = *num * 10 - (*str - '0');
	else
		*num = *num * 10 + (*str - '0');
	return (TRUE);
}

int	get_atoi(char *str, int *num)
{
	int	minus;

	*num = 0;
	minus = 0;
	while ((*str == '+' || *str == '-') && *str != '\0')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	if (!ft_isdigit(*str))
		return (FALSE);
	while (*str != '\0' && !is_whitespace(*str))
	{
		if (!atoi_helper(str, num, minus))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
