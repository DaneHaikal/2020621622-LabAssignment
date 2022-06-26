#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

  void sigint_handler(int sig);
  void sigtstp_handler(int sig);
  void sigquit_handler(int sig);
  int num;

  if (signal(SIGINT, sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  else if (signal(SIGTSTP,sigtstp_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  else if (signal(SIGQUIT,sigquit_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  printf("Enter a number: \n");
  scanf("%d", &num);
  printf("You've entered number %d \n",num);
  return 0;
}

void sigint_handler(int sig)
{
  printf("This is a special signal handler for INT signal");
}

void sigtstp_handler(int sig)
{
  printf("This is a special signal handler for TSTP signal");
}

void sigquit_handler(int sig)
{
  printf("This is a special signal handler for SIGQUIT signal");
}

