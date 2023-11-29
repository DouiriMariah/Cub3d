/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tox.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:32:36 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 20:00:53 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_order(char **map)
{
	if (map && map[0] && map[1] && map[2] && map[3] && map[4] && map[5])
	{
		if (map[0][0] == 'N' && map[1][0] == 'S'
			&& map[2][0] == 'W' && map[3][0] == 'E'
			&& map[4][0] == 'F' && map[5][0] == 'C')
			return (0);
	}
	printf("error map\n");
	free_double_char(map);
	exit(1);
}

int	ft_continue(t_data *data, int tmp, char **map, char **newmap)
{
	if (tmp == 0)
	{
		data->i = -1;
		data->j = 0;
		data->b = 0;
		data->y = 0;
		data->len = 0;
	}
	else if (tmp == 1)
	{
		data->b = 0;
		continue_2(data, 0, map, newmap);
		if (map[data->i])
		{
			data->len = ft_strlen(map[data->i]) - data->j;
			if (map[data->i][data->j] && (map[data->i][data->j]
				== 'N' || map[data->i][data->j]
				== 'W' || map[data->i][data->j] == 'E'
				|| map[data->i][data->j] == 'S' || map[data->i][data->j]
					== 'F' || map[data->i][data->j] == 'C') && data->len != 0)
				return (0);
		}
	}
	return (1);
}

char	**ft_space_info(t_data *data, char **map)
{
	char	**newmap;

	newmap = NULL;
	ft_continue(data, 0, map, NULL);
	newmap = malloc(sizeof(char *) * (count_line(map) + 1));
	if (!newmap)
		return (NULL);
	while (map[++data->i])
	{
		if (!ft_continue(data, 1, map, newmap))
		{
			newmap[data->y] = malloc(sizeof(char) * (data->len + 1));
			if (!newmap)
				return (NULL);
			while (map[data->i][data->j])
				newmap[data->y][data->b++] = map[data->i][data->j++];
			newmap[data->y++][data->b] = '\0';
		}
		else if (map[data->i])
			newmap[data->y++] = ft_strdup(map[data->i]);
		else
			break ;
	}
	newmap[data->y] = 0;
	return (continue_2(data, 2, map, newmap), newmap);
}

int	check_line(char *str)
{
	static int	var;
	static int	nb_line;
	int			i;

	i = 0;
	nb_line++;
	if (var > 0)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (!str[i] && var == 1)
		{
			var++;
			return (nb_line);
		}
	}
	while (str[i] && (str[i] == '1' || str[i] == '0' || element(str[i])))
	{
		if (str[++i] == '\n')
		{
			if (var == 0)
				var = 1;
		}
	}
	return (0);
}

int	verif_error_line(t_data *data, char *str, int index)
{
	int	i;
	int	last;

	i = -1;
	data->b = 0;
	last = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			data->b++;
	}
	last = data->b;
	while (str[--i] && str[i] != '1' && str[i] != '0' && !element(str[i]))
	{
		if (str[i] == '\n')
			last--;
	}
	if (index < last)
	{
		close(data->fd);
		free(str);
		printf("Error map\n");
		exit(1);
	}
	return (0);
}
