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
<<<<<<< HEAD
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

=======

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

>>>>>>> dcc1e100b40f06a2304078c52c7a944f9edd0d9a
				if (argument == NULL || !atoi(argument))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
<<<<<<< HEAD
				instruction.f = push;
			}
			else if (strcmp(opcode, "pall") == 0)
				instruction.f = pall;
=======
				line_number = atoi(argument);
				instruction.f = push;
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				instruction.f = pall;
			}
>>>>>>> dcc1e100b40f06a2304078c52c7a944f9edd0d9a
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (instruction.f != NULL)
<<<<<<< HEAD
				instruction.f(&stack, line_number);
=======
			{
				instruction.f(&stack, line_number);
			}
>>>>>>> dcc1e100b40f06a2304078c52c7a944f9edd0d9a
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
