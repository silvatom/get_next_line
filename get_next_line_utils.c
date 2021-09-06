/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:06:56 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/06 01:18:57 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		len_s;

	len_s = 0;
	while (s[len_s])
		len_s++;
	ptr = (char *)s;
	i = 0;
	while (i < len_s + 1)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (ptr = 0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len_s1;
	int		i;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	dst = (char *)malloc(sizeof(char) * len_s1 + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*ret;
	int				i;

	if (!s1 || !s2)
		return (0);
	len_s1 = (ft_strlen(s1));
	len_s2 = (ft_strlen(s2));
	ret = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		ret[len_s1 + i] = s2[i];
		i++;
	}
	ret[len_s1 + i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	size_m;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if ((s_len - start) < len)
		size_m = (s_len - start);
	else
		size_m = len;
	subs = (char *)malloc(sizeof(char) * (size_m + 1));
	if (!subs)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = (char)s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
