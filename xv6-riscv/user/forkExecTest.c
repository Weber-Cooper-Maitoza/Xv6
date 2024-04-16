#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define DEFAULT_FORKS 2

int main(int argc, char * argv[]) {
  int numCount;
  int forks;

  if (argc < 2 || argc > 3){
    printf("Usage: number to count <count>, (optional) number of fork <forks>\n");
    exit(1);
  }
  numCount = atoi(argv[1]);
  if (numCount < 1) {
    printf("ERROR: number to count <count> must be a positive integer.\n");
    exit(1);
  }
  if (argc == 3) {
    forks = atoi(argv[2]);
    if (forks < 1) {
      printf("ERROR: forks must be a positive integer.\n");
      exit(1);
    }
  }
  else {
    forks = DEFAULT_FORKS;
  }

  for (int i = 0; i < forks; i++) {
    int pid = fork();
    if (pid == 0) {
      char* argument[] = {"countNums", argv[1], itoa(i+1), 0};
      exec("countNums", argument);
    }
  }
  wait(0);

  exit(0);
}
