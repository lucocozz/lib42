/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_oa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:12:14 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/05 13:28:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static t_oparg g_oa[3] = {
	{"free", 0}, {"sep", ""}, {NULL, NULL}
};

static void		ft_setoa(int noa, va_list ap)
{
	int		i;
	int		j;
	t_oparg	oa;

	i = 0;
	if (!noa)
		return ;
	while (i < noa)
	{
		j = 0;
		oa = va_arg(ap, t_oparg);
		while (g_oa[j].name != NULL && ft_strcmp(g_oa[j].name, oa.name))
			j++;
		if (g_oa[j].name != NULL)
			g_oa[j].data = oa.data;
		i++;
	}
}

static void		ft_free_arg(char *s1, char *s2, int n)
{
	if (n == 1 || n == 3)
		ft_memdel((void**)&s1);
	if (n == 2 || n == 3)
		ft_memdel((void**)&s2);
}

char			*ft_strjoin_oa(char *s1, char *s2, int noa, ...)
{
	int		i;
	int		j;
	char	*strnew;
	va_list	ap;

	i = 0;
	j = 0;
	va_start(ap, noa);
	ft_setoa(noa, ap);
	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = ft_calloc(ft_strlen(s1) + ft_strlen(s2) +
	ft_strlen((char*)g_oa[1].data) + 1, sizeof(char));
	if (strnew == NULL)
		return (NULL);
	ft_strcpy(strnew, s1);
	ft_strcat(strnew, (char*)g_oa[1].data);
	ft_strcat(strnew, s2);
	ft_free_arg(s1, s2, (int)g_oa[0].data);
	va_end(ap);
	return (strnew);
}
