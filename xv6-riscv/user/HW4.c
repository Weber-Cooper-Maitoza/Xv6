//#include "kernel/param.h"
//#include "kernel/types.h"
//#include "kernel/stat.h"
//#include "user/user.h"
//#include "kernel/fs.h"
//#include "kernel/fcntl.h"
//#include "kernel/syscall.h"
//#include "kernel/memlayout.h"
//#include "kernel/riscv.h"

#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
  // variable to store the magic number
  int magic; 
  magic = getMagic();
  printf("current magic number is the following: %d\n", magic);

  // increment the magic number by 15
  printf("---Changing magic number by 15---\n");
  incMagic(15);  
  magic = getMagic();
  printf("current magic number is the following: %d\n", magic);

  // now check the system calls for process name
  printf("current process name: ");

  // getProcName should print the name to the screen
  getProcName();    
  printf("\n"); 

  printf("---Changing Process Name to newName---\n");
  // now change the proc name to newName
  modProcName("newName");  

  printf("The process name is now: ");
  getProcName();
  printf("\n");

  printf("---Changing Process Name to CooperMaitozaProcess---\n");
  // now change the proc name to [testName]
  modProcName("CooperMaitozaProcess");  

  printf("The process name is now: ");
  getProcName();
  printf("\n");

  printf("---Retreiving the current magic number---\n");
  magic = getMagic();
  printf("current magic number is the following: %d\n",magic);

  printf("---Changing magic number to -3---\n");
  incMagic(-3);
  magic = getMagic();
  printf("current magic number is the following: %d\n",magic);

  // adding by 4
  printf("---Adding 4 to magic number---\n");
  incMagic(getMagic() + 4);

  magic = getMagic();
  printf("current magic number is the following: %d\n",magic);

  exit(0);
}
