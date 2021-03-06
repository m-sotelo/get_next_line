/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:03:51 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/14 12:26:38 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_utils.h"
# endif
char	*first_read(char **buf, char *res, int fd);
char	*trim_line(char *res, char **buf);
char	*read_line(char **buf, char *res, int fd);
char	*get_next_line(int fd);


