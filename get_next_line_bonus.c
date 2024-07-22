/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:08:58 by rrabeari          #+#    #+#             */
/*   Updated: 2024/04/17 13:20:46 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stock[1000];
	char		*buffer;
	char		*return_value;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stock[fd])
		{
			free(stock[fd]);
			stock[fd] = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return_value = get_full_line_bonus(fd, stock[fd], buffer);
	free(buffer);
	buffer = NULL;
	stock[fd] = store_static_var_bonus(return_value);
	return (return_value);
}

char	*get_full_line_bonus(int fd, char *stock, char *buffer)
{
	int		i;
	char	*temp;

	i = 1;
	if (!stock)
		stock = ft_strdup("");
	if (!stock)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && ft_strlen(stock) == 0))
			return (free(stock), NULL);
		buffer[i] = 0;
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n') || buffer[0] == '\n')
			break ;
	}
	return (stock);
}

char	*store_static_var_bonus(char *value)
{
	int		i;
	char	*stock;

	i = 0;
	stock = NULL;
	if (value == NULL)
		return (stock);
	while (value[i] != '\n' && value[i] != '\0')
		i++;
	if (value[i] == '\n')
	{
		stock = ft_substr(value, i + 1, ft_strlen(value) - i);
		value[i + 1] = 0;
	}
	return (stock);
}
