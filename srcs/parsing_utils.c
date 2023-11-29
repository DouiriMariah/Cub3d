/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:33:31 by aperis            #+#    #+#             */
/*   Updated: 2022/10/12 19:40:47 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_char(char c, int *pos)
{
	if ((c != '1' && c != '0' && c != ' ')
		&& !check_pos(c, pos))
		return (0);
	return (1);
}

int	check_pos(char c, int *pos)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		(*pos)++;
		return (1);
	}
	return (0);
}

int	only_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	spacenull(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (0);
	return (1);
}

int	check_zero(t_data *data, char **map, int i, int j)
{
	if (j == 0 && map[i][j] == '0')
		return (0);
	if ((i && j > (int)ft_strlen(map[i - 1]))
		|| ((i < count_line(data->map) - 2)
			&& j > (int)ft_strlen(map[i + 1])))
		return (0);
	if ((i && !spacenull(map[i - 1][j]))
		|| ((i < count_line(data->map) - 2)
			&& !spacenull(map[i + 1][j])))
		return (0);
	if ((j && !spacenull(map[i][j - 1]))
		|| (j + 1 && !spacenull(map[i][j + 1])))
		return (0);
	return (1);
}
