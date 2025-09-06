/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:01:10 by sganesan          #+#    #+#             */
/*   Updated: 2025/09/06 21:01:43 by sganesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		parse_input(char *s, int *clues);
void	print_error(void);
int		solve(int **grid, int *clues, int row, int col);

static int	**alloc_grid(void)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **)malloc(4 * sizeof(int *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(4 * sizeof(int));
		if (!grid[i])
			return (NULL);
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

static void	free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;

	if (argc != 2)
		return (print_error(), 0);
	clues = (int *)malloc(16 * sizeof(int));
	if (!clues)
		return (print_error(), 0);
	if (!parse_input(argv[1], clues))
		return (free(clues), print_error(), 0);
	grid = alloc_grid();
	if (!grid)
		return (free(clues), print_error(), 0);
	if (!solve(grid, clues, 0, 0))
		print_error();
	free_grid(grid);
	free(clues);
	return (0);
}
