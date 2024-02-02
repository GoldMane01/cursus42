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
char	*cmdname(char *s);
void	split_args(char **params, char *args);
char	**get_params(char *file, char *cmd);
char	**cmdargs(char **arg);

void	first_cp1(int *fd, char **arg);
void	first_cp2(int *link, char **arg);
void	second_cp1(int *link, char **arg);
void	second_cp2(int *link, char **arg);

#endif