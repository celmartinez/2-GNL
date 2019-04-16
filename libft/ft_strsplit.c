/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:07:30 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:33:34 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (i < ft_strlen(s))
	{
		while (((char *)s)[i] == c)
		{
			if (((char *)s)[i + 1] == '\0')
				return (words);
			i++;
		}
		while (((char *)s)[i] != c && ((char*)s)[i] != '\0')
			i++;
		words++;
	}
	return (words);
}

static char		**ft_filltab(char const *s, char c, char **tab)
{
	int		w;
	size_t	i;
	int		j;

	w = 0;
	i = 0;
	if (s[0] == '\0')
	{
		tab[i] = NULL;
		return (tab);
	}
	while (i < count_words(s, c))
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[w] == c && s[w] != '\0')
			w++;
		while (s[w] != c && s[w] != '\0')
			tab[i][j++] = s[w++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s != NULL)
	{
		if (!(tab = malloc(sizeof(char *) * (count_words(s, c) + 1))))
			return (NULL);
		return (ft_filltab(s, c, tab));
	}
	return (NULL);
}
