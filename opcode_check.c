#include "monty.h"

/**
 * get_code - Entry Point
 * Desc: get_code function
 * @s: char pointer type
 * Return: Function that checks from the list
 */
int (*get_code(char *inst))(stack **, unsigned int)
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
