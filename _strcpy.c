#include "simple_shell.h"

/**
 * *_strcpy -  copies the string pointed to by src.
 * @dest: The first pointer.
 * @src: The second pointer
 *
 * Return: To the value of char.
 */
char *_strcpy(char *dest, char *src)
{
int i;
i = 0;
while (src[i] != 0)
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
