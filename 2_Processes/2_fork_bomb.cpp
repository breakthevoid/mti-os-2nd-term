#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}

/*
      L1
    /    \
  L2      L2
 /  \    /  \
L3  L3  L3  L3

*/

