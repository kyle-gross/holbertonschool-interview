#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * unstable - checks if a sandpile is unstable
 * @grid: the grid to check
 * Return: 1 if unstable, 0 if stable
 */
int unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}

	return (0);
}

/**
 * copyGrid - copies a grid
 * @src: grid to copy
 * @dest: grid to copy to
 * Return: void
 */
void copyGrid(int src[3][3], int dest[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

/**
 * sandpiles_sum - computes the sum of 2 3x3 sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int temp[3][3], i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (unstable(grid1))
	{
		print_grid(grid1);
		memset(temp, 0, sizeof(temp));
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4)
				{
					temp[i][j] += grid1[i][j] - 4;
					if (i - 1 >= 0)
						temp[i - 1][j]++;
					if (i + 1 <= 2)
						temp[i + 1][j]++;
					if (j - 1 >= 0)
						temp[i][j - 1]++;
					if (j + 1 <= 2)
						temp[i][j + 1]++;
				}
				else
					temp[i][j] += grid1[i][j];
			}
		}
		copyGrid(temp, grid1);
	}
}
