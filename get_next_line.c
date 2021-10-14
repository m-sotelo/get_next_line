/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:28:06 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/14 15:35:43 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*first_read(char **buf, char *res, int fd)
{
	ssize_t	i;

	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = read(fd, res, BUFFER_SIZE);
	if (i <= 0)
	{
		free(res);
		return (NULL);
	}
	res[i] = '\0';
	*buf = ft_strdup(res);
	free(res);
	return (*buf);
}

char	*trim_line(char *res, char **buf)
{
	int		start;
	int		len;
	char	*aux;

	free(res);
	start = 0;
	len = 0;
	aux = *buf;
	if(!*aux)
		return (NULL);
	while(*aux != '\n' && *aux)//si pongo el if abajo necesito esa condicion en el while?
	{
		aux++;
		start++;
	}
	start++;
	//aux++;
	res = ft_substr(*buf, 0, start);
	if(!*aux)//leaks aqui cuando quede algo en el buf pero luego no sobre que hacer?
//	{
//		free(*buf);
		return(res);
//	}
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

char	*read_line(char **buf, char *res, int fd){
	ssize_t	i;

	i = 0;

	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(*buf, '\n') == NULL && *buf)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == 0)
			break ;
		res[i] = '\0';
		*buf = ft_strjoin(*buf, res);
	}
	free(res);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;

	res =  NULL;	
	if (!buf)
	{		
		buf = first_read(&buf, res, fd);
		if (buf == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	buf = read_line(&buf, res, fd);
	res = trim_line(res, &buf);
	if (buf == NULL)
	{	
		free(buf);
		return (NULL);
	}
	return(res);
}

/*int main()
{
	int	i;
	char *x;
	
	x = NULL;
	i = 0;
	i  = open("test.txt" , O_RDONLY);
	x = get_next_line(i);
	printf("esto es el final:%s", x);
	x = get_next_line(i);
	printf("esto es el fina2:%s", x);
//	x = get_next_line(i, 3);
//	printf("esto es el fina3:%s", x);
}/*
