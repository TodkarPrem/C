#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signum) 
{
	printf("Handled the signal\n");
}

int main() 
{
	int pid;
	signal(SIGKILL, sig_handler);
	pid = fork();
	if (pid==0) {
		kill(getppid(), SIGKILL);
		exit(0);
	} else {
		sleep(20);
	}
	return 0;
}
