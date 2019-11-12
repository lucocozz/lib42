/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:52:26 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/12 19:14:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;
	size_t	last_size;

	if (ptr == NULL)
		return (malloc(size));
	last_size = sizeof(ptr);
	if (size <= last_size)
		return (ptr);
	if ((new = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(new, ptr, last_size);
	free(ptr);
	return (new);
}
