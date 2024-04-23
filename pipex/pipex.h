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

//LIB
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//COMMANDS
void	free_commands(char **commands);
char	*get_argv(char *arg);
char	**get_commands(char *argv[], int argc);

//PATH
char	**find_paths(char *envp[]);
int		check_access(char *path, char *command);
char	*get_path(char *path, char *command);
char	*check_paths(char **allpaths, char *command);
char	*cmdname(char *s, char *envp[]);

//UTILS
int		argv_size(char **argv);
char	**awk_split(char *command);
int		last_command(char **commands, int cmdnum);
int		create_temp_file();
char	*cmdname(char *s, char *envp[]);
char	**free_ptr(char	**ptr);

//READS
void	read_temp(int link[]);
void	read_input(int link[], char *infile);
void	read_file(char *infile, int cmdnum, int fd[]);

//WRITES
void	write_output(int link[], char *path, char **arg, char *outfile);
void	write_temp(int link[], char *path, char **arg);

#endif
