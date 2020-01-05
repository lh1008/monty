#include "monty.h"

/**
 * op_push - Entry Point
 * Desc: op_push function
 * @stack: stack_t type
 * @line_number: unsigned int type
 * Return: New node in stack
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value = yoyo.meet;
	int me;

	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (validate(value))
	{
		me = atoi(value);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = me;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * op_pall - Entry point
 * Desc: op_pall function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that prints all the elements of a list pall.
 **/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	while (gotit != NULL)
	{
		printf("%d\n", (gotit)->n);
		gotit = (gotit)->next;
	}
	(void)line_number;
}

/**
 * op_pint - Entry point
 * Desc: op_pint function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that prints the elements of a list in pint.
 **/
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	if (gotit != NULL)
	{
		printf("%d\n", (gotit)->n);
	}
	else
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	(void)line_number;
}
