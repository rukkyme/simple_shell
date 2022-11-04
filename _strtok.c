#include "simple_shell.h"
/**
* _strtok - tokenized
* @str: var type string
* @limi: delimitator
* Return: Var type char *
*/
char *_strtok(char *str, char *limi)
{
	int i;
	static char *s;

	if (!str)
		str = s;
	i = *str++;
	while (_strchr(limi, i))
	{
		if (i == 0)
			return (0);
		i = *str++;
	}
	--str;
	s = str + _strcspn(str, limi);
	if (*s != 0)
	{
		*s = 0;
		s++;
	}
	return (str);
}
/**
 * _strchr - locates character
 * @stri: var type char *
 * @car: var type char
 * Return: pointer to the first occurrence of the character
 */
char *_strchr(char *stri, char car)
{
	while (*stri != 0)
	{
		if (*stri == car)
			return (stri);
		stri++;
	}
	if (*stri == car)
		return (stri);
	return (0);
}

/**
 * _strcspn - The length
 * @str: Var type char *
 * @pre: prefix string
 * Return: Unsigned int
 */
unsigned int _strcspn(char *str, char *pre)
{
	unsigned int len = 0, i = 0;

	while (str[len] != 0)
	{
		int flag = 0;

		for (i = 0; pre[i] != 0; i++)
		{
			if (str[len] == pre[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			len++;
		else
			break;
	}
	return (len);
}
