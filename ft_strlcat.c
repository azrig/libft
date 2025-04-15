/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:12:08 by azrig             #+#    #+#             */
/*   Updated: 2024/11/19 11:16:02 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	if (size == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= destlen)
		srclen += size;
	else
		srclen += destlen;
	i = 0;
	while (src[i] && destlen < size - 1)
	{
		dest[destlen] = src[i];
		i++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (srclen);
}
