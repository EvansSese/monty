#include "monty.h"
/**
 * is_integer - Check if argument is int
 * @argument: Char to check
 *
 * Return: 1 if is integer, 0 otherwise
 */
int is_integer(const char *argument)
{
	if (argument == NULL || *argument == '\0')
		return (0);
	else
		return (1);
}
