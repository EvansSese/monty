#include "monty.h"

/**
 * sub - subtracts top element of stack from second top element of the stack.
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
