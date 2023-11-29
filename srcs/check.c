/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:12:42 by aperis            #+#    #+#             */
/*   Updated: 2022/10/15 19:30:42 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	only_empty(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	verif_next(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n'
			&& str[i] != 'E' && str[i] != 'S' && str[i] != 'N'
			&& str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	check2(char *str, char *next_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
		i++;
	if (i >= 2)
		i--;
	if (i >= 1)
		i--;
	while (next_str[j])
	{
		if (str && only_empty(str, i) && next_str[j] == '0'
			&& verif_next(next_str) && str[i])
			return (0);
		j++;
	}
	return (1);
}

int	check(char *str, char *next_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
		i++;
	if (i >= 2)
		i--;
	if (i >= 1)
		i--;
	while (str && i && str[i] != '\n')
		i--;
	while (str && str[i])
	{
		if (verif_next(str) && ((str[i] == '0'
					&& only_empty(next_str, 0))
				|| (next_str[j] == '0' )))
			return (0);
		i++;
	}
	return (1);
}

int	double_check(char *str, char *next_str)
{
	if (check(str, next_str) == 0)
		return (0);
	if (check2(str, next_str) == 0)
		return (0);
	return (1);
}
