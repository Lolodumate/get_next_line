/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:37:36 by laroges           #+#    #+#             */
/*   Updated: 2023/06/23 17:37:39 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*      Ressources :
 *      https://www.youtube.com/watch?v=-Mt2FdJjVno
 *      https://www.youtube.com/watch?v=vngK2abJ3_I&list=PLrWjmAwvhv61YP-7o56hnPINM80HsdJcw
 *      https://harm-smits.github.io/42docs/projects/get_next_line
 *      https://www.developpez.net/forums/d2120348/c-cpp/c/debuter/explication-methode-get-next-line/
 *      https://github.com/Yaten/42-get_next_line/blob/master/README.md
 *
 *      read(int fildes, void *buf, size_t nbytes)
 *
 *      libft interdite !!
 *
 *      Le programme doit compiler avec les options habituelle + -D BUFFER_SIZE=n
 *
 *      Une ligne se termine soit par un \n, soit par un EOF.
 *
 *      Ne pas copier le \n dans le paramètre d'entrée **line de la fonction
 *
 *      Valeurs retournées :
 *              1 si une ligne a été lue
 *              0 si la lecture a été correctement faite
 *              -1 si la lecture a échoué
 *
 *      Lorsqu'on atteint le EOF :
 *              On stocke le buffer dans **line. Si le buffer est vide, alors on stocke une string vide dans **line.
 *              On libère la mémoire allouée à l'exception du dernier bufferà stocker dans **line
 *
 *      Commentaire fonctionnement de read :
 *
 *      read : lit sur le "descripteur de fichier" 0 (c'est à dire l'entrée standard),et  place ce qui a été lu en mémoire à partir de l'adresse de buf, en se limitant à au plus 1 caractère. Ca tombe bien puisque buf, c'est une variable qui peut contenir qu'au plus 1 caractère.

si la lecture a réussi, écrit (write) ce caractère converti sur la sortie standard (1).

A part ça c'est programmé avec les pieds, la variable c n'est pas utilisée, et read peut aussi retourner -1 en cas d'erreur, ce qui provoquera une boucle.
 *
 *
 */

#include "get_next_line.h"

int	ft_get_n(int fd, char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

char	*ft_putline(int fd, char *line)
{
	char	*str;

	if (line == NULL)
		return (NULL);
	str = ft_calloc(sizeof(char), ft_get_n(fd, line) + 2);
	if (str == NULL)
		return (NULL);
	while (*line++ && *line != '\n')
	{
		*str = *line;
		str++;
	}
	if (*line == '\n')
		*str = '\n';
	return (&str[0]);
}

char	*ft_read_line(int fd, char *line)
{
	int		ret;
	char	*buffer;

	ret = 0;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!ift_strchr(line, '\n' && ret > 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
			buffer[ret] = '\0';
			line = ft_strjoin(line, buffer);	
	}
	free(buffer);
	return (line);
}

char    *ft_get_next_line(int fd, char *line)
{
        static char		ret;
        char    *stash;

        len = 0;
        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        stash = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (stash == NULL)
                return (-1);
        ret = ft_read_line(fd, line);
	free(stash);
        return (ret);
}
