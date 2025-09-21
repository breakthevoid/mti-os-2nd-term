#include <stdio.h>
#include <unistd.h>

void forkexample()
{
    // child process because return value zero
    if (fork() == 0)
    {
        pid_t child = getpid();
        printf("Hello from Child!, My id is %d\n", child);
    }
    
    // parent process because return value non-zero
    else 
    {
        pid_t parent = getppid();
        printf("Hello from Parent! My id is %d\n", parent);
    }
}

int main()
{
    forkexample();
    return 0;
}


