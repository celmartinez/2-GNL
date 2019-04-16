/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:34:28 by cmartine          #+#    #+#             */
/*   Updated: 2018/06/01 04:43:56 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char		*s2;
	size_t		ls1;
	size_t		i;

	i = 0;
	s2 = NULL;
	ls1 = (ft_strlen(s));
	if (ls1 < n)
		n = ls1;
	if (!(s2 = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (i < n)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
