/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:02:34 by sganesan          #+#    #+#             */
/*   Updated: 2025/09/06 21:03:02 by sganesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	parse_input(char *s, int *clues);

int	parse_input(char *s, int *clues)
{
	int	len;
	int	i;

	len = 0;
	while (s[len])
		len++;
	if (len != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (s[i] < '1' || s[i] > '4')
				return (0);
			clues[i / 2] = s[i] - '0';
		}
		else if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
