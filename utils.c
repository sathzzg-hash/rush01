/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:03:43 by sganesan          #+#    #+#             */
/*   Updated: 2025/09/06 21:03:57 by sganesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s);
void	print_error(void);
int		is_in_row(int **grid, int row, int val);
int		is_in_col(int **grid, int col, int val);

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	print_error(void)
{
	ft_putstr("Error\n");
}

int	is_in_row(int **grid, int row, int val)
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (grid[row][c] == val)
			return (1);
		c++;
	}
	return (0);
}

int	is_in_col(int **grid, int col, int val)
{
	int	r;

	r = 0;
	while (r < 4)
	{
		if (grid[r][col] == val)
			return (1);
		r++;
	}
	return (0);
}
