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
	char *value = verify.meet;
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
 * Return: Function that prints all the elements of a list.
 **/
void op_pall(stack_t **stack, unsigned int line_number)
{
	size_t counter = 0;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		counter++;
		*stack = (*stack)->next;
	}
	(void)line_number;
}
