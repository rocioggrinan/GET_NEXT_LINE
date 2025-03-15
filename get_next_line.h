/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogarci2 <rogarci2@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-15 19:17:01 by rogarci2          #+#    #+#             */
/*   Updated: 2025-03-15 19:17:01 by rogarci2         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*===================Includes=================*/
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*===================Buffer_size=================*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*===================Functions=================*/
char	*get_next_line(int fd);
int		ft_strlen_r(const char *a);
char	*ft_strchr_r(const char *s, int c);
char	*ft_substr_r(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_r(char *s1, char *s2);
char	*ft_strdup_r(const char *src);

#endif