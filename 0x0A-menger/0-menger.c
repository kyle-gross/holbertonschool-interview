#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int x, y, i, print, size = pow(3, level);

	if (level == 0)
		printf("#\n");
	if (level > 0)
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size; y++)
			{
				print = 1;
				for (i = 1; i < size; i *= 3)
				{
					if (((x / i) % 3 == 1) && ((y / i) % 3 == 1) && print)
						print = 0;
				}
				if (print)
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
