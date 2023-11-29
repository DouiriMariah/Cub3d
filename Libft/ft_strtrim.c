/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:55:16 by aperis            #+#    #+#             */
/*   Updated: 2021/12/08 17:18:45 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	j = i;
	while (s1[j])
		j++;
	while (j && ft_isset(s1[j - 1], set) && j > i)
		j--;
	dest = malloc(sizeof(char) * ((j - i) + 1));
	if (!(dest))
		return (NULL);
	ft_strlcpy(dest, &s1[i], ((j - i) + 1));
	return (dest);
}
