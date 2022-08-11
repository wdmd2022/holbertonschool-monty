#include "monty.h"

/**
 * _pushop - pushes element onto the stack
 * @stack: double pointer to the stack
 * @linenumber: line number
 * Return: Nothing
 */
void _pushop(stack_t **stack, unsigned int linenumber)
{
	int reqargint;
	int i = 0;
	char *reqargstring = oparg.requiredarg;
	stack_t *coolblock;

	if (!reqargstring)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linenumber);
		exit(EXIT_FAILURE);
	}
	for (; reqargstring[i] != '\0'; i++)
	{
		if (!isdigit(reqargstring[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", linenumber);
			exit(EXIT_FAILURE);
		}
	}
	reqargint = atoi(reqargstring);
	coolblock = malloc(sizeof(stack_t));
	if (!coolblock)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	coolblock->prev = NULL;
	coolblock->n = reqargint;

	if (*stack == NULL)
	{
		coolblock->next = NULL;
	}
	else
	{
		coolblock->next = *stack;
		(*stack)->prev = coolblock;
	}
	*stack = coolblock;
}

/**
 * _pallop - prints all values on the stack, starting from the top
 * @stack: top of the stack
 * @linenumber: line number
 * Return: nothing
 */
void _pallop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *surfer = *stack;

	while (surfer)
	{
		printf("%i\n", surfer->n);
		surfer = surfer->next;
	}
}
