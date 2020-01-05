#include "monty.h"

/**
 * op_add - Entry point
 * Desc: op_add function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that adds the top two elements of the stack.
 **/
void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next->n = (*stack)->n + (*stack)->next->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_nop - Entry point
 * Desc: op_nop function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that implements the nop opcode
 **/
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
