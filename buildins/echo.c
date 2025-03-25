#include <stdio.h>
#include <stdlib.h>
#include "ft_strncmp.c"

void	ft_echo(int argc, char **argv)
{
	int i = 1;
	int newline = 1;

	if (argc > 1 && ft_strncmp(argv[1], "-n", 2) == 0)
	{
		newline = 0;
		i++;
	}

	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i < argc - 1)
			printf(" ");
		i++;
	}

	if (newline)
		printf("\n");
}

int main(int argc, char **argv)
{
	ft_echo(argc, argv);
	return (0);
}