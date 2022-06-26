#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void) {
  for(int i = 1; i < 5; i++) {
    pid_t pid = fork();

    if(pid == 0) {
      char name[50];
      printf("\nName: ");
      scanf("%s", name);
      printf("Your Name is %s.\n", name);
      exit(0);
    }
    else  {
      wait(NULL);
    }
  }
  printf("\nJob is done\n");
 
  return EXIT_SUCCESS;
}

