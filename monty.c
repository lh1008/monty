#include "monty.h"
/**
 * main - Entry point
 * Desc: main function
 * @argc: argument count for monty program
 * @argv: one-dimensional array vector containing arguments
 * Return: Main receives arguments
 **/
int main(int argc, char *argv[])
{
	if (argc > 2 || argc == 1)
	{ fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		receive(argv[1]);
	}
	return (0);
}

/**
 * receive - Entry
 * Desc: receive function
 * @file_name: pointer to char
 * Return: Reads if arguments, opens file, reads, and closes.
 **/
int receive(char *file_name)
{
	char *inst;
	size_t bufsize = 1024;
	stack_t *stack = NULL;
	unsigned int line_count = 0;
	void (*f)(stack_t **, unsigned int);

	yoyo.fd = fopen(file_name, "r");
	if (yoyo.fd == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	else
	{	yoyo.buffer = malloc(1024);
		if (yoyo.buffer == NULL)
		{	fprintf(stderr, "Error: malloc failed\n");
			free(yoyo.buffer);
			exit(EXIT_FAILURE);
		}
		while (getline(&(yoyo.buffer), &bufsize, yoyo.fd) != -1)
		{	line_count++;
			inst = strtok(yoyo.buffer, "\n\t\r ");
			yoyo.meet = strtok(NULL, "\n\t\r ");
			if (inst != NULL && inst[0] != '#')
			{	f = _get_code(inst);
				if (f != NULL)
					f(&stack, line_count);
				else
				{	fprintf(stderr, "L%u: unknown instruction %s\n", line_count, inst);
					free(yoyo.buffer);
					free_space(&stack);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	free(yoyo.buffer);
	yoyo.buffer = NULL;
	fclose(yoyo.fd);
	return (0);
}
