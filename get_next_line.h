/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:24:25 by marvin            #+#    #+#             */
/*   Updated: 2024/12/13 23:24:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*ft_strchr(const char *str, int ch);
char		*get_next_line(int fd);
char		*getbefore(char *str);
char		*getafter(char *str);
char		*joinfunc(char *str, char *buffer, int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);

#endif