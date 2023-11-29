/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:29:44 by aperis            #+#    #+#             */
/*   Updated: 2021/12/04 15:54:59 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j + 1)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
	}
	return (str);
}

void	ft_start(char *str, long int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == 1)
		str[i++] = '-';
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			i;
	char		*str;

	nb = n;
	i = 0;
	str = malloc(sizeof(char) * ft_count(nb) + 1);
	if (!str)
		return (NULL);
	ft_start(str, nb);
	return (ft_strrev(str));
}
