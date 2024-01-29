#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/wait.h>

int		ft_strlen(const char *s);
int		count_strs(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_cmd(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif