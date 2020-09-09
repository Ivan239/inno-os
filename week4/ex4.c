#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define MAX_INPUT_LENGTH 100

int main(){
    char input[MAX_INPUT_LENGTH];

    while (1) {
        fgets(input, MAX_INPUT_LENGTH, stdin);

        int pid = fork();
        if (pid == 0) {
            system(input);
            return 0;
        }
    }
}