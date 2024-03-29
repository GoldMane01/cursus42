/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:19:41 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/09 16:19:42 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Applies the function f to each element of the s pointer.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = -1;
	while (s[++i])
		(*f)(i, &s[i]);
}
