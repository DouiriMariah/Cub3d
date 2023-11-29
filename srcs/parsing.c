/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:33:14 by aperis            #+#    #+#             */
/*   Updated: 2022/10/15 20:10:50 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_check_arg(int ac, char **av)
{
	int		i;

	if (check_directory(av) == 0)
		exit(0);
	if (ac != 2)
	{
		printf("Error, wrong number of arguments.\n");
		exit(0);
	}
	i = ft_strlen(av[1]);
	if (i < 4)
	{
		printf("Error, the map doesn't exist. Please enter a valid file\n");
		exit(0);
	}
	i--;
	if ((av[1][i] != 'b') || (av[1][i - 1] != 'u') || (av[1][i - 2] != 'c')
		|| (av[1][i - 3] != '.'))
	{
		printf("Error, the map has to finish in .cub\n");
		exit(0);
	}
}

int	close_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (only_wall(map[i]) == 0)
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (check_zero(data, map, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	i--;
	if (only_wall(map[i]) == 0)
		return (0);
	return (1);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	pos = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (check_char(map[i][j], &pos) == 0)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	if (pos != 1)
		return (0);
	return (1);
}

void	get_pos(t_data *data)
{
	int	a;
	int	i;
	int	j;

	i = -1;
	j = -1;
	a = 0;
	while (data->map[++i])
	{
		while (data->map[i][++j])
		{
			if (check_pos(data->map[i][j], &a))
			{
				data->pos = data->map[i][j];
				data->pos_x = i + 0.5;
				data->pos_y = j + 0.5;
				data->psx = i;
				data->psy = j;
				break ;
			}
		}
		if (a != 0)
			break ;
		j = 0;
	}
}

int	parsing(t_data *data)
{
	int	i;

	i = 0;
	get_pos(data);
	if (check_valid_map(data->mapinfo) == 0)
		return (0);
	if (check_map(data->map) == 0)
		return (0);
	if (close_map(data, data->map) == 0)
		return (0);
	return (1);
}
