/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:10:49 by sganesan          #+#    #+#             */
/*   Updated: 2025/09/06 21:11:05 by sganesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_in_row(int **grid, int row, int val);
int		is_in_col(int **grid, int col, int val);
int		check_row(int **grid, int row, int left, int right);
int		check_col(int **grid, int col, int top, int bottom);

int		solve(int **grid, int *clues, int row, int col);
void	print_grid(int **grid);

void	print_grid(int **grid)
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ch = '0' + grid[r][c];
			write(1, &ch, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

static int	is_valid(int **grid, int *clues, int row, int col)
{
	if (col == 3 && !check_row(grid, row, clues[8 + row], clues[12 + row]))
		return (0);
	if (row == 3 && !check_col(grid, col, clues[col], clues[4 + col]))
		return (0);
	return (1);
}

int	solve(int **grid, int *clues, int row, int col)
{
	int	val;
	int	nr;
	int	nc;

	if (row == 4)
		return (print_grid(grid), 1);
	val = 1;
	while (val <= 4)
	{
		if (!is_in_row(grid, row, val) && !is_in_col(grid, col, val))
		{
			grid[row][col] = val;
			if (is_valid(grid, clues, row, col))
			{
				nr = row + (col + 1) / 4;
				nc = (col + 1) % 4;
				if (solve(grid, clues, nr, nc))
					return (1);
			}
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}
