#include "monty.h"

/**
 * add - Adds 2 values
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
}
