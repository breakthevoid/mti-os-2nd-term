#include <stdio.h>
#include <unistd.h>

void forkexample()
{
    // child process because return value zero
    if (fork() == 0)
    {
        char *args[] = {"./EXEC", NULL};
        execv(args[0], args);
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


