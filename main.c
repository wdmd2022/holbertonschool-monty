#include "monty.h"

/**
 * main - entry point for the function that executes monty byte code files
 *
 * @argc: number of arguments in argv array (vector)
 * @argv: array of strings, contains all arguments passed
 *
 * Return: 0 if successful, -1 (EXIT_FAILURE) otherwise
 */
int main(int argc, char *argv[])
{
	FILE *filepointer; /* the file to open */
	unsigned int linenumber = 1; /* to keep track for error msgs */
	char *buffer = NULL; /* for getline */
	size_t size = 0; /* so getline allocates the buffer itself */
	stack_t *stack = NULL; /* stack pointer */
	char *opcode = NULL; /* will put the opcode here from strtok */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monthy file\n");
		exit(EXIT_FAILURE);
	}
	filepointer = fopen(argv[1], "r"); /* open file into a stream */
	if (filepointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &size, filepointer)) != -1)
	{
		if (*buffer == '\n')
		{
			linenumber++;
			continue;
		}
		opcode = strtok(buffer, " \n\t"); /* get the opcode */
		if (!opcode)
		{
			linenumber++;
			continue;
		}
		oparg.requiredarg = strtok(NULL, " \n\t");
		executeopcode(opcode, &stack, linenumber);
		linenumber++;
	}
	freestack(&stack);
	free(buffer);
	fclose(filepointer);
	return (0);
}
/**
 * executeopcode - pick an opcode and do it
 * @opcode: string, opcode provided in the file
 * @stack: address of stack to execute opcode operation on
 * @linenumber: int, keeping track of line number for error purposes
 * Return: nothing, nada, zip, zilch
 */
void executeopcode(char *opcode, stack_t **stack, unsigned int linenumber)
{
	int index;
	instruction_t opcodestocheck[] = {
		{"push", _pushop},
		{"pall", _pallop},
		{NULL, NULL}
	};
	void (*operation)(stack_t **stack, unsigned int line_number);

	for (index = 0; opcodestocheck[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, opcodestocheck[index].opcode) == 0)
			operation = opcodestocheck[index].f;
	}
	if (!operation)
	{
		fprintf(stderr, "L:%u: unknown instruction %s\n", linenumber, opcode);
		exit(EXIT_FAILURE);
	}
	operation(stack, linenumber);
}
