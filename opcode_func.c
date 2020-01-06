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
		free_space(stack);
		exit(EXIT_FAILURE);
	}
	else if (validate(value))
	{
		me = atoi(value);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		free_space(stack);
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
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pop - Entry point
 * Desc: op_pop function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that eliminates the top element of a stack.
 **/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	if (gotit != NULL)
	{
		gotit = (*stack)->next;
		if (gotit != NULL)
			gotit->prev = NULL;
		free(*stack);
		*stack = gotit;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_swap - Entry point
 * Desc: op_swap function
 * @stack: pointer to pointer to stack_t
 * @line_number: unsigned int type
 * Return: Function that the swaps the two elements of the stack.
 **/
void op_swap(stack_t **stack, unsigned int line_number)
{
	int gotit_n;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		gotit_n = (*stack)->next->n;
		(*stack)->next->n = (*stack)->n;
		(*stack)->n = gotit_n;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
