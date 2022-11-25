/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:07:46 by etlaw             #+#    #+#             */
/*   Updated: 2022/11/25 17:23:41 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	free(buffer);
	return (line);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

char	*readfile(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_substr("", 0, 0);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	byte_read = 1;
	while (!ft_strchr(res, '\n') && byte_read != 0)
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			break ;
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	buffer[fd] = readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}

// int	main()
// {
// 	char *line = 0;
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(fd);

// 	}
// }