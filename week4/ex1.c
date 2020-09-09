#include <stdio.h>
#include <zconf.h>

int main() {
    int n = 10;
    int pid = fork();

    if (pid == 0)
        printf("Hello from child [%d - %d]\n", getpid(), n);
    else
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    return 0;
}

// In the output strings are shuffled since each one comes from separate process.
// Meanwhile, processes are executed in parallel