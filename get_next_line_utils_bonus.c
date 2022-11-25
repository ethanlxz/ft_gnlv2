/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils _bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:07:50 by etlaw             #+#    #+#             */
/*   Updated: 2022/11/25 17:19:17 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i1;
	int		i2;

	i1 = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * sizetotal + 1);
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i1] != 0)
	{
		res[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2] != 0)
	{
		res[i1] = s2[i2];
		i1++;
		i2++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (0);
	if (ft_strlen(s) < (size_t)start)
		return (ft_substr("", 0, 0));
	s += start;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (!subs)
		return (0);
	subs[len] = '\0';
	while (len--)
		subs[len] = s[len];
	return (subs);
}

int	ft_strchr(const char *string, int tofind)
{
	char	*str;

	str = (char *)string;
	while (*str != tofind && *str != '\0')
		str++;
	if (*str == tofind)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
