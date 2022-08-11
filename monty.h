#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct oparg_s - opcode required argument structure for global access
 * @requiredarg: argument associated with opcode (command from file)
 *
 * Description: needed to access opcode's argument across files
 */
typedef struct oparg_s
{
	char *requiredarg;
} oparg_t;

oparg_t oparg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void executeopcode(char *opcode, stack_t **stack, unsigned int linenumber);
void _pushop(stack_t **stack, unsigned int linenumber);
void _pallop(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void freestack(stack_t **stack);
void _pintop(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void _popop(stack_t **stack, __attribute__((unused))unsigned int linenumber);

#endif
