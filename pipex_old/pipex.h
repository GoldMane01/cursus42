/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:17:11 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:17:13 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/wait.h>

int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_strs(char const *s);
void	split_args(char **params, char *args);
char	**get_params(char *file, char *cmd);
void	free_split(char **params);
char	**cmdargs(char **arg);
char	*cmdname(char *s, char *envp[]);
void	first_cp1(int *fd, char **arg);
void	first_cp2(int *link, char **arg, char *envp[]);
void	second_cp1(int *link);
void	second_cp2(int *link, char **arg, char *envp[]);
char	**ft_split(char const *s, char c);
char	**find_paths(char *envp[]);
int		count_strs_split(char const *s, char c);
int		check_access(char *path, char *command);
char	*get_path(char *path, char *command);
int		find_awk(char *argv[]);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
