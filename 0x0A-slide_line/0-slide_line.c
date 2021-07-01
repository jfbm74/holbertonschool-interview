#include "slide_line.h"
/**
* slide_line - slide & merge it to the left or to the right. Identical numbers,
* if they are contiguous or separated by zeros, should be merged
* @line: points to an array of integers
* @size: number of elements in the array
* @direction:  elements, that must be slided & merged to the direction
* Return: 1 success or 0 failure
*/
int slide_line(int *line, size_t size, int direction)
{
	size_t match = 0, repeated = 0, initial = 1, stop = size;
	int flag = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		match = size - 1;
		repeated = size - 1;
		initial = -1;
		stop = -1;
	}

	while (match != stop)
	{
		if (*(line + match) != 0)
		{
			if (flag == *(line + match))
			{
				*(line + match) += flag;
				flag = -1;
			}
			else
			{
				flag = *(line + match);
				if ((direction == SLIDE_LEFT && match != 0)
					||
					((direction == SLIDE_RIGHT && match != (size - 1))))
					if (*(line + repeated) != 0)
						repeated += initial;
			}
			*(line + repeated) = *(line + match);
			if (repeated != match)
				*(line + match) = 0;
		} match += initial;
	}
	return (1);
}
