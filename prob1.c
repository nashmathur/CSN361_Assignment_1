#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork() == 0) {
		// Created child 1 of Parent.
		int id = getpid();
		if (fork() == 0) {
			// Created grandchild1 of Parent (child1 of child1)
			sleep(2);
			// printf("Created grandchild1 of Parent (child1 of child1)\n");
			printf("First Grand Child : %d ", getpid());
			printf("Parent id : %d\n", getppid());
		} else {
			// child1 continues
			if (fork() == 0) {
				// Created grandchild2 of Parent (child2 of child1)
				sleep(2);
				printf("Second Grand Child : %d ", getpid());
				printf("Parent id : %d\n", getppid());
			} else {
				// child 1 process continues and pid get printed
				printf("First Child : %d ", getpid());
				printf("Parent id : %d\n", getppid());
			}
		}
		wait(NULL);
		wait(NULL);
	} else {
		// Parent process continues

		if (fork() == 0) {
			// Created child 2 of Parent
			if (fork() == 0) {
				// Created grandchild3 of Parent (child1 of child2)
				sleep(2);
				printf("Third Grand Child : %d ", getpid());
				printf("Parent id : %d\n", getppid());
			} else {
				// child2 continues
				if (fork() == 0) {
					// Created grandchild4 of Parent (child2 of child2)
					sleep(2);
					printf("Fourth Grand Child : %d ", getpid());
					printf("Parent id : %d\n", getppid());
				} else {
					// child2 process continues and pid get printed
					printf("Second Child : %d ", getpid());
					printf("Parent id : %d\n", getppid());
				}
			}
			wait(NULL);
			wait(NULL);
		} else {
			// Parent process continues here
			sleep(5);
			printf("Parent : %d\n", getpid());		
		}
	}
}
