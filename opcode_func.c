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

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * op_pall - Entry Point
 * Desc: op_pall function
 * @a: int type
 * @b: int type
 * Return: The sum
 */
int op_pall()
{

}
