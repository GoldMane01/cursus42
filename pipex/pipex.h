#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

int		ft_strlen(const char *s);
int		count_strs(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_filename(char *s);

#endif