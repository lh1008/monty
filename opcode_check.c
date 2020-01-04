#include "monty.h"

/**
 * _get_code - Entry Point
 * Desc: _get_code function
 * @inst: char pointer type
 * Return: Function that checks from the list
 */
void (*_get_code(char *inst))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	int mv_list;

	while (ops[mv_list].opcode != NULL)
	{
		if (strcmp(inst, ops[mv_list].opcode))
		{
			return (ops[mv_list].f);
		}
		mv_list++;
	}
	return (NULL);
}
