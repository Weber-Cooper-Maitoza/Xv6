#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char* argv[]){
  int nums;
  int childNum = 0;

  if (argc < 2 || argc > 3) {
    printf("Usage: number to count <count>, (optional) child number <childNum>.\n");
    exit(1);
  }

  nums = atoi(argv[1]);
  childNum = atoi(argv[2]);

  for (int i = 1; i <= nums; i++) {
    printf("Child %d: %d\n", (childNum), i);
    sleep(10);
  }
  exit(0);
}
