/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:37:08 by laroges           #+#    #+#             */
/*   Updated: 2023/06/23 17:37:19 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif


char			*ft_get_next_line(int fd, char **line);
char			*ft_putline(int fd, char *line);
char			*ft_read_line(int fd, char *line);
int		ft_get_n(char *line);
int		ft_count_line(char *line);
size_t	ft_strlen(char *str);

ft_strchr
ft_strjoin
ft_calloc

# endif
