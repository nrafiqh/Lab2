#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void childTask() {
	char name[100], name2[100];
	printf("\nWhat is your first name?\n");
	scanf("%s", name);
	printf("\nWhat is your second name?\n");
	scanf("%s", name2);
	printf("\nYour name is %s %s\n", name, name2 );
	}

void parentTask() {
	printf("\nJob is done.\n");
	}

int main(void) {

	for (int i=1; i<5; i++) {
	  pid_t pid = fork();

	  if (pid == 0) {
		childTask();
		return EXIT_SUCCESS;
	  }
	  else if (pid > 0) {
		wait(NULL);
		}
	  }
	  parentTask();
	  return EXIT_SUCCESS;
}

