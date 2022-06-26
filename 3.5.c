#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(void) {

  void sigint_handler(int sig);

  if(signal(SIGINT,sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
     }

  while(1) {
    int pipefds[2];
    int num, buffer, m=0, flag=0;

 
    pipe(pipefds);
 
    pid_t pid = fork();
 
    if(pid == 0) {
      printf("Enter a number: ");
      scanf("%d", &num);
      close(pipefds[0]);
      write(pipefds[1], &num, sizeof(num));
 
      exit(EXIT_SUCCESS);
    }
 
    if(pid > 0) {
      wait(NULL); 
 
      close(pipefds[1]); 
      read(pipefds[0], &buffer, sizeof(buffer));
      close(pipefds[0]); 
      m = buffer/2;
      for(int i = 2; i <= m; i++)
      {
         if(buffer%i==0)
	 {
		printf("\n%d is not Prime Number\n\n",buffer);
		flag=1;
		return 0;;
	 }
      }
      if(flag == 0)
      {
	printf("\n%d is Prime Number\n\n",buffer);
	return 0;
      }
    }
  }
 
  return EXIT_SUCCESS;
}

void sigint_handler(int sig)
{
     printf("Process Terminated\n");
}
