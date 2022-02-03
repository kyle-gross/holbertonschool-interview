#include "slide_line.h"

/**
 * slide_line - slides a line based on the 2048 game
 * @line: the array representing a line
 * @size: the size of the array
 * @direction: the direction to slide the numbers
 * Return: 1 if success or 0 if failure
 */
int slide_line(int *line, size_t size, int direction) {
	if (direction == SLIDE_RIGHT) {
		slide_right(line, size);
		combine(line, size, direction);
		slide_right(line, size);
	}
	else if (direction == SLIDE_LEFT) {
		slide_left(line, size);
		combine(line, size, direction);
		slide_left(line, size);
	}
	else
		return (0);
	return (1);
}

void slide_right(int *line, size_t size) {
	int i, j = 0;

	for (i = j = size - 1; i >= 0; i--) {
		while (line[j] == 0)
			j--;
		if (j < 0)
			break;
		line[i] = line[j];
		if (i != j)
			line[j] = 0;
		j--;
	}
}

void combine(int *line, size_t size, int direction) {
	size_t i;

	if (direction == SLIDE_LEFT) {
		for (i = 1; i < size; i++) {
			if (line[i - 1] == line[i] && line[i] != 0) {
				line[i - 1] *= 2;
				line[i] = 0;
			}
		}
	}
	if (direction == SLIDE_RIGHT) {
		for (i = size - 2; (int)i >= 0; i--) {
			if (line[i + 1] == line[i] && line[i] != 0) {
				line[i + 1] *= 2;
				line[i] = 0;
			}
		}
	}
}

void slide_left(int *line, size_t size) {
	size_t i, j = 0;

	for (i = 0; i < size; i++) {
		while (line[j] == 0 && j < size)
			j++;
		if (j >= size)
			break;
		line[i] = line[j];
		if (i != j && j < size)
			line[j] = 0;
		j++;
	}
}
