/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:24:07 by nakoo             #+#    #+#             */
/*   Updated: 2023/06/21 13:33:20 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h = haystack;
	const char	*n = needle;
	const char	*h2;
	const char	*n2;
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < needle_len)
		return (NULL);
	while (*h)
	{
		h2 = h;
		n2 = n;
		while (*h2 && *n2 && (*h2 == *n2))
		{
			h2++;
			n2++;
		}
		if (*n2 == '\0')
			return ((char *)h);
		h++;
	}
	return (NULL);
}
