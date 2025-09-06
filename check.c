/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:10:09 by sganesan          #+#    #+#             */
/*   Updated: 2025/09/06 21:10:16 by sganesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* prototypes */
int	visible_from_left(int *arr);
int	visible_from_right(int *arr);
int	check_row(int **grid, int row, int left, int right);
int	check_col(int **grid, int col, int top, int bottom);

int	visible_from_left(int *arr)
{
	int	max;
	int	cnt;
	int	i;

	max = 0;
	cnt = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	visible_from_right(int *arr)
{
	int	max;
	int	cnt;
	int	i;

	max = 0;
	cnt = 0;
	i = 3;
	while (i >= 0)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			cnt++;
		}
		i--;
	}
	return (cnt);
}

int	check_row(int **grid, int row, int left, int right)
{
	int	arr[4];
	int	c;

	c = 0;
	while (c < 4)
	{
		arr[c] = grid[row][c];
		c++;
	}
	return (visible_from_left(arr) == left
		&& visible_from_right(arr) == right);
}

int	check_col(int **grid, int col, int top, int bottom)
{
	int	arr[4];
	int	r;

	r = 0;
	while (r < 4)
	{
		arr[r] = grid[r][col];
		r++;
	}
	return (visible_from_left(arr) == top
		&& visible_from_right(arr) == bottom);
}
