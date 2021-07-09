#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: nothing
 */
void menger(int level)
{
	int i, j, w, h, flag = 1, size;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			h = i, w = j;
			while (flag)
			{
				if (h % 3 == 1 && w % 3 == 1)
				{
					printf(" ");
					break;
				}
				if (h == 0 || w == 0)
				{
					printf("#");
					break;
				}
				h = h / 3;
				w = w / 3;
			}
		}
		printf("\n");
	}
}
