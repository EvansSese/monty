#include "monty.h"
/**
 * main - Entry point
 * @argc: Arg count
 * @argv: Arg vector
 *
 * Return: Int
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_length = 0;
	unsigned int line_number = 0;
	char *opcode;
	ssize_t read_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_file = getline(&line, &line_length, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode != NULL && opcode[0] != '#')
		{
			instruction_t instruction;

			instruction.opcode = opcode;
			instruction.f = NULL;
			if (strcmp(opcode, "push") == 0)
			{
				char *argument = strtok(NULL, " \n");

				if (argument == NULL || !atoi(argument))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				line_number = atoi(argument);
				instruction.f = push;
			}
			else if (strcmp(opcode, "pall") == 0)
				instruction.f = pall;
			else if (strcmp(opcode, "pint") == 0)
				instruction.f = pint;
			else if (strcmp(opcode, "pop") == 0)
				instruction.f = pop;
			else if (strcmp(opcode, "swap") == 0)
				instruction.f = swap;
			else if (strcmp(opcode, "add") == 0)
				instruction.f = add;
			else if (strcmp(opcode, "nop") == 0)
				instruction.f = nop;
			else if (strcmp(opcode, "sub") == 0)
                                instruction.f = sub;
			else if (strcmp(opcode, "div") == 0)
				instruction.f = f_div;
			else if (strcmp(opcode, "mul") == 0)
                                instruction.f = mul;
			else if (strcmp(opcode, "mod") == 0)
				instruction.f = mod;
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (instruction.f != NULL)
				instruction.f(&stack, line_number);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
