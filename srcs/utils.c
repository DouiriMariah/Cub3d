/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:12:31 by aperis            #+#    #+#             */
/*   Updated: 2022/10/15 20:12:59 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	end_space(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0] != 'N' && map[i][0] != 'W' && map[i][0] != 'E'
			&& map[i][0] != 'S' && map[i][0] != 'F' && map[i][0] != 'C')
		{
			while (map[i][j])
			{
				if (map[i][j] != '0' && map[i][j] != '1'
					&& map[i][j] != ' ' && map[i][j] != '\n')
					return (0);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count_line(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	nb_text(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if ((map[i][0] == 'N' && map[i][1] == 'O')
			|| (map[i][0] == 'S' && map[i][1] == 'O')
			|| (map[i][0] == 'E' && map[i][1] == 'A')
			|| (map[i][0] == 'W' && map[i][1] == 'E')
			|| map[i][0] == 'F' || map[i][0] == 'C')
				j++;
			i++;
	}
	if (j != 6)
	{
		free_double_char(map);
		printf("Error map\n");
		exit (1);
	}
}

int	element(char c)
{
	if (c == 'E' || c == 'N' || c == 'S' || c == 'W')
		return (1);
	return (0);
}
