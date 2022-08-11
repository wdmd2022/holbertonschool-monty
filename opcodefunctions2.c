#include "monty.h"

/**
 * _addop - adds top two elements of the stack. Stores the result in the 2nd
 * from top element and removes the top element, shortening the stack by one.
 * @stack: top of the stack
 * @linenumber: line number
 * Return: nothing
 */
void _addop(stack_t **stack, unsigned int linenumber)
{
	int sum;
	stack_t *jumpmasterflash;

	if ((stack == NULL) || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	sum = (((*stack)->n) + (*stack)->next->n);
	jumpmasterflash = (*stack)->next;
	(*stack)->next->n = sum;
	(*stack)->next->prev = NULL;
	free(*stack);
	*stack = jumpmasterflash;
}

/**
 * _nopop - does nothing, but does it without messing stuff up
 * @stack: top of the stack
 * @linenumber: line number;
 * Return: Nothing, sensibly
 */
void _nopop(__attribute__((unused))stack_t **stack, unsigned int linenumber)
{
	(void)linenumber;
}
