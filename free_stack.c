#include "monty.h"
/**
 * free_stack - Frees the stack
 * @stack: Stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
}
