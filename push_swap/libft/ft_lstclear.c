/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:25 by tpipi             #+#    #+#             */
/*   Updated: 2023/11/09 15:31:21 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst && lst[0] && del)
	{
		if (lst[0]->next)
			ft_lstclear(&(lst[0]->next), del);
		ft_lstdelone(lst[0], del);
		lst[0] = NULL;
	}
}
