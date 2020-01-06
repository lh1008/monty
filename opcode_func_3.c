#include "monty.h"

/**
 * op_mod - Entry point
 * Desc: op_mod function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that divides the top two elements of the stack.
 **/
void op_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free_space(stack);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n = (*stack)->next->n % (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
