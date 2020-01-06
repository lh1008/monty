#include "monty.h"

/**
 * _get_code - Entry Point
 * Desc: _get_code function
 * @inst: char pointer type
 * @line: unsigned int line_counter from monty.c
 * Return: Function that checks from the list
 */
void (*_get_code(char *inst, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
		{"pop", op_pop}, {"swap", op_swap}, {"add", op_add},
		{"nop", op_nop}, {"sub", op_sub}, {"mul", op_mul},
		{"div", op_div}, {"mod", op_mod}, {NULL, NULL}
	};
	
	int mv_list = 0;

	while (ops[mv_list].opcode != NULL)
	{
		if (strcmp(inst, ops[mv_list].opcode) == 0)
		{
			return (ops[mv_list].f);
		}
		mv_list++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line, inst);
	exit(EXIT_FAILURE);
}
