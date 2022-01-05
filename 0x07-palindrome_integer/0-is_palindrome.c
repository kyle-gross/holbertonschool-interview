#include "palindrome.h"

/**
 * is_palindrome - determines if an integer is a palindrome
 * @n: number to check 
 * Return: 1 if `n` is a palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	char buffer[1024];
	int len = 0, j = 0, i = 0;

	itoa(n, buffer, 10);
	len = strlen(buffer);
	
	if (len == 0 || len == 1)
		return (1);

	j = len / 2;
	i = j;

	if (len % 2 != 0)
	{
		j++;
		i--;
	}
	else
		i = j - 1;

	for (; i >= 0; i--)
	{
		if (buffer[i] != buffer[j])
			return (0);
		j++;
	}

	return (1);
}

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 * Return: void
 */
void rev_string(char *s)
{
	int c, i, len = strlen(s);

	for (i = 0, c = len - 1; i < c; i++, c--)
	{
		char tmp = s[i];

		s[i] = s[c];
		s[c] = tmp;
	}
}


/**
 * itoa - converts integer to string
 * @num: number to convert
 * @str: buffer of string
 * @base: decimal place to convert to
 * Return: converted string
 */
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0';
 
    rev_string(str);
 
    return (str);
}
