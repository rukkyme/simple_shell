#include "simple_shell.h"

/**
 * _strcat - Concatenates two strings..
 * @dest: The first pointer.
 * @src: The second pointer
 *
 * Return: To the value of dest.
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;
while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0')
{
dest[i + j] = src[j];
j++;
}
dest[i + j] = '\0';
return (dest);
}
