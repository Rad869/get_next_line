/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:49:30 by rrabeari          #+#    #+#             */
/*   Updated: 2024/04/17 13:19:40 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*value;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		i = 1;
	else if (len < (ft_strlen(s) - start))
		i = len + 1;
	else
		i = ft_strlen(s) - start + 1;
	value = (char *) malloc(sizeof(*s) * i);
	i = 0;
	if (value == 0)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			value[j++] = s[i];
		i++;
	}
	return (value[j] = 0, value);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*value;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	value = (char *) malloc(sizeof(*s1) * (len1 + len2 + 1));
	if (value == 0)
		return (NULL);
	while (i < (len1 + len2))
	{
		if (i < len1)
			value[i] = s1[i];
		else
			value[i] = s2[i - len1];
		i++;
	}
	value[i] = 0;
	return (value);
}
