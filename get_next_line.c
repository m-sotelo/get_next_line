/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:28:06 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/13 20:16:51 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*int	check_read(char *buf, ssize_t count)
{
	int	i;
	int	j;
	int k;

	i = (int)count;
	j = 0;
	k = 0;
	while (buf[j] != '\0')
	{
		if (buf[j] == '\n')
			k++;
		j++;
	}
	if (buf[i] == '\n' && k == 1)
		return (0);	//equal
	j = 0;
	while (i > 0)
	{
		if (buf[j] == '\n')	
			return (1);		//more
		j++;
		i--;
	}
	return (2);				//less
}*/

char	*trim_line(char *res, char **buf)
{
	int		start;
	int		len;
	char	*aux;

	start = 0;
	len = 0;
	aux = *buf;
	while(*aux != '\n')
	{
		aux++;
		start++;
	}
	start++;
	res = ft_substr(*buf, 0, start);
	while(*aux)
	{
		aux++;
		len++;
	}
	aux = ft_substr(*buf, start, len);
	free(*buf);
	*buf = aux;
return(res);
}

char	*read_line(char **buf, int fd){
	ssize_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(*buf, '\n') == NULL && *buf)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i < 0)
		{
			free(res);
			return (NULL);
		}
		res[i] = '\0';
		if (!*buf)
			*buf = ft_strdup(res);
		else
			*buf = ft_strjoin(*buf, res);
	}
	free(res);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;
	
	res = NULL;
	buf = read_line(&buf, fd);
	if (buf == NULL)
		return (NULL);
	res = trim_line(res, &buf);
	return(res);
}

/*int main()
{
	int	i;
	char *x;
	
	x = NULL;
	i = 0;
	i  = open("test3.txt" , O_RDONLY);
	i = 27;
	x = get_next_line(i);
	printf("esto es el final:%s\n", x);
//	x = get_next_line(i, 3);
//	printf("esto es el fina2:%s", x);
//	x = get_next_line(i, 3);
//	printf("esto es el fina3:%s", x);
}*/
