/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:15 by skimura           #+#    #+#             */
/*   Updated: 2025/06/01 21:46:05 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_check_nl(const char *s);
char	*ft_strjoin_free(char *old, const char *buffer);
char	*ft_substr(const char *s, size_t start, size_t len);

#endif
