#include "palindrome.h"

/**
 * is_palindrome - determines if an integer is a palindrome
 * @n: number to check 
 * Return: 1 if `n` is a palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n, new_n = 0, x = 0;

	while (n / 10 > 0)
	{
		x = n % 10;
		new_n = (10 * new_n) + x;
		n /= 10;
	}
	new_n = (10 * new_n) + x;

	if (original != new_n)
		return (0);

	return (1);
}
