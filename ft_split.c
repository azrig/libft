/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:28:51 by azrig             #+#    #+#             */
/*   Updated: 2024/11/18 10:28:51 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_fill(char **str, char const *s, char c, int n)
{
	int	start;
	int	i;
	int	word_i;

	start = 0;
	i = 0;
	word_i = 0;
	while (word_i < n)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[word_i] = ft_substr(s, start, i - start);
		if (!str[word_i])
		{
			ft_free(str, word_i);
			return (NULL);
		}
		word_i++;
	}
	str[word_i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!ft_fill(arr, s, c, ft_wordcount(s, c)))
		return (NULL);
	return (arr);
}
