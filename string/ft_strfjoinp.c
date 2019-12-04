/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoinp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:22:42 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 23:06:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strfjoinp(char *s1, char const *s2, int prefix)
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (strnew == NULL)
		return (NULL);
	ft_strcpy(strnew, (prefix ? (char*)s2 : s1));
	ft_strcat(strnew, (prefix ? s1 : (char*)s2));
	ft_memdel((void**)&s1);
	return (strnew);
}
