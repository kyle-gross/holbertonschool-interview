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

	for (; i >= 0; i--)
	{
		if (buffer[i] != buffer[j])
			return (0);
		j++;
	}

	return (1);
}

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
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    rev_string(str);
 
    return str;
}
