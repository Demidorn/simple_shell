#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * main - entry
 *
 * Return: 0 always
 */

int main(void)
{
	pid_t my_pid;
	pid_t ppid;

	my_pid = getpid();

	printf("%d\n", my_pid);
	printf("my pid is %u\n", my_pid);
	ppid = getppid();
	printf("parent ID is %d\n", ppid);
	printf("parent ID %u\n", ppid);
	return (0);
}
