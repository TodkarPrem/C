#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>

int child[2];

void my_isr(int n)
{
	if (n == SIGCHLD) {
		printf("Child killed before 5 sec.\n");
		raise(SIGKILL);
	}
	else {
		printf("Parent kills child after 5 sec.\n");
		kill(child[0], SIGKILL);
		raise(SIGKILL);
	}
}

int main()
{
	int a;
	if ((child[0] = fork()) == 0) {
		printf("child pid = %d\n", getpid());
		srand(getpid());
		a = rand() % 10 + 1;
		printf("a = %d\n", a);
		sleep(a);
	}
	else {
		child[1] = getpid();
		printf("parent pid = %d child pid = %d\n", getpid(), child[0]);
		signal(SIGCHLD, my_isr);
		signal(SIGALRM, my_isr);
		alarm(5);
		while(1);
	}

	return 0;
}
