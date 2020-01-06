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
		free_space(stack);
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

#include "monty.h"

/**
 * op_sub - Entry point
 * Desc: op_sub function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that substracts the top two elements of the stack.
 **/
void op_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_mul - Entry point
 * Desc: op_mul function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that multiplies the top two elements of the stack.
 **/
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next->n = (*stack)->next->n * (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_div - Entry point
 * Desc: op_div function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that divides the top two elements of the stack.
 **/
void op_div(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free_space(stack);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
