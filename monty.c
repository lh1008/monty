#include "monty.h"
make_it yoyo = {NULL};
/**
 * main - Entry point
 * Desc: main function
 * @argc: argument count for monty program
 * @argv: one-dimensional array vector containing arguments
 * Return: Reads if arguments, opens file, reads, and closes.
 **/
int main(int argc, char *argv[])
{
	FILE *fd;
	char *buf, *inst;
	size_t bufsize = 1024;
	stack_t *stack = NULL;
	unsigned int line_count = 0;
	void (*f)(stack_t **, unsigned int);

	if (argc > 2 || argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			buf = malloc(1024);
			if (buf == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(buf);
				exit(EXIT_FAILURE);
			}
			while (getline(&buf, &bufsize, fd) != -1)
			{
				line_count++;
				inst = strtok(buf, "\n\t\r ");
				yoyo.meet = strtok(NULL, "\n\t\r ");
				if (inst != NULL)
				{
					f = _get_code(inst);
					if (f != NULL)
						f(&stack, line_count);
					else
					{
						fprintf(stderr, "L%u: unknown instruction %s", line_count, inst);
						free(buf);
						free_space(&stack);
						exit(EXIT_FAILURE);
					}
				}
			}
		}
		free(buf);
		buf = NULL;
		fclose(fd);
	}
	return (0);
}
