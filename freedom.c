#include "monty.h"

/**
 * freestack - free the stack
 * @stack: the stack to free
 * Return: nothing at all
 */
void freestack(stack_t **stack)
{
	stack_t *memoryreaper;

	if (stack == NULL)
		return;
	if (*stack == NULL)
		return;
	while (*stack)
	{
		memoryreaper = *stack;
		*stack = (*stack)->next;
		free(memoryreaper);
	}
}
