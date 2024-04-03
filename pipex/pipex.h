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
char	**ft_split(char const *s, char c);
char	**get_commands(char *argv[], int argc);
int		create_temp_file();
//void	execute_command(char **commands, int cmdnum, char *infile, char *envp[], char *outfile);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**find_paths(char *envp[]);
char	*get_path(char *path, char *command);
int		check_access(char *path, char *command);
void	write_temp(int link[], char *path, char **arg);
char	*get_path(char *path, char *command);
char	**find_paths(char *envp[]);
char	*cmdname(char *s, char *envp[]);
int		check_access(char *path, char *command);
int		last_command(char **commands, int cmdnum);
char	**cmdargs(char **arg);
//void	execute_command(char **cmds, int cmdn,  char *env[], char *out);
void	execute_command(int fd[], char **cmds, int cmdn,  char *env[], char *out);
void	read_file(char *infile, int cmdnum, int fd[]);
void	write_output(int link[], char *path, char **arg, char *outfile);

#endif
