#include "monty.h"
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
	char *buf, *inst, *num;
	size_t bufsize = 1024;

	if (argc > 2 || argc == 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			buf = malloc(1024);
			if (buf == NULL)
			{
				printf("Error: malloc failed\n");
				free(buf);
				exit(EXIT_FAILURE);
			}
			while (getline(&buf, &bufsize, fd) != -1)
			{
				inst = strtok(buf, "\n\t\r ");
				if (inst != NULL)
				{
					printf("%s\n", inst);
				}
				num = strtok(NULL, "\n\t\r ");
				if (num != NULL)
				{
					printf("%s\n", num);
				}
			}
		}
	}
	return (0);
}
