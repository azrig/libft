/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:42:07 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 17:44:08 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (!lst || !new)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = *lst;
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}
