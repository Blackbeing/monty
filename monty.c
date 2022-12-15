#include "monty.h"

/**
 * call_func -- Call function by optcode
 * @stack: pointer to array of stack_t pointers
 * @opt: string argument
 * @arg: string argument
 */

void call_func(stack_t **stack, char *opt, char *arg)
{
	int index;

	instruction_t options[] = {
	{"push", stack_push}, {"pall", stack_pall}, {NULL, NULL} };

	if (opt)
	{
		index = 0;
		while (options[index].opcode)
		{
			if (strcmp(options[index].opcode, opt) == 0)
			{
				if (strcmp(opt, "pall") == 0)
					options[index].f(stack, 0);
				else
					options[index].f(stack, atoi(arg));
			}
			index++;
		}
	}
}

/**
 * main -- run main program
 * @argc: int arg
 * @argv: string arg
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	char *opt, *arg;
	stack_t *p;

	p = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, stream) != -1)
	{
		opt = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");
		call_func(&p, opt, arg);
	}

	free(line);
	fclose(stream);

	return (0);
}
