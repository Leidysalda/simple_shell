#include "MyShell.h"

/**
 *
 *
 */

void function_fork(char *buffer, char **command)
{
	int y, status;
	pid_t pidC;
	struct stat st;

	pidC = fork();

	if (pidC == -1)
	{
		perror("Error Fork");
		free(buffer);
		free(command);
		exit (98);
	}
	if (pidC == 0)
	{
		y = stat(command[0], &st);
		if (y != 0)
			command[0] = get_path(command[0]);
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error Execve");
			free(command), free(buffer);
			exit(0);
		}
	}
	else if (pidC > 0)
		wait(&status);
	free(command), free(buffer);
}
