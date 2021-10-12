/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:28:06 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/12 20:07:33 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_read(char *buf, ssize_t count)
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
}

char	*bigger_count(char *res, char **buf)
{
	char	*aux;
	int		i;

	aux = res;
	while(*aux != '\n')
		aux++;
	aux++;
	while(*aux)
	{
		buf[0][i] = *aux;
		*aux = '\0';
		i++;
		aux++;
	}
return(res);
}

char	*smaller_count(char *res, char **buf, int BUFFER_SIZE, int fd){
	ssize_t	i;
	int		k;

	i = 0;
	k = ft_strlen(res) - 1;
	if (!*buf)
		*buf = ft_strdup(res);
	else
		*buf = ft_strjoin(*buf, res);
	while (ft_strchr(res, '\n') == NULL && buf)
	{
		i = read(fd, res, BUFFER_SIZE);
		res[i] = '\0';
		*buf = ft_strjoin(*buf, res);
		k = k + i;
	}
	free(res);
	return (*buf);
}

char	*get_next_line(int fd, size_t BUFFER_SIZE)
{
	static char	*buf;
	char		*res;
	size_t		i;
	int			j;
	
	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = read(fd, res, BUFFER_SIZE);
	res[i] = '\0';
	j = check_read(res, ft_strlen(res));
	if (j == 0)
		return (res);
	else if (j == 1)
	{

	}
	else if (j == 2)
	{
		res = smaller_count(res, &buf, BUFFER_SIZE, fd);
		printf("res despues de smaller es:%s\n",res);
		res = bigger_count(res, &buf);
		printf("res despues de bigger:%s\n",res);
	}
	return (buf);
}
int main()
{
	int	i;
	char *x;
	
	x = NULL;
	i = 0;
	i  = open("test.txt" , O_RDONLY);
	x = get_next_line(i, 3);
	i = 0;
	while(i < 27)
	{
		printf("%i:%c",i,x[i]);
		i++;
	}
	printf("\n");
//	x = get_next_line(i, 3);
//	printf("esto es el fina2:%s", x);
//	x = get_next_line(i, 3);
//	printf("esto es el fina3:%s", x);
}
