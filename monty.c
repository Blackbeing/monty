#include "monty.h"

/**
 * tokenize -- Parse string to only two tokens (del leading, trailing spaces)
 * @str: pointer to string
 *
 * Return: opt_arg_t instance
 */
opt_arg_t tokenize(char *str)
{
	char *s = str;
	char *delim = " ";
	char *opt, *arg;
	opt_arg_t token;

	opt = strtok(s, delim);
	arg = strtok(NULL, delim);

	token.opt = opt;
	token.arg = arg;
	return (token);

}

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	opt_arg_t token;

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

	nread = getline(&line, &len, stream);
	while (nread != -1 )
	{
		/* fwrite(line, nread, 1, stdout); */
		/* TODO parse string */
		token = tokenize(line);
		printf("%s -> %s", token.opt, token.arg);
		nread = getline(&line, &len, stream);
	}
	free(line);
	fclose(stream);

	return (0);
}
