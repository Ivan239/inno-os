#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, height, width;
    sscanf(argv[1], "%lu", &n);

    for (height = 0; height < n; height++) {
        for (width = 0; width < 2*n-1; width++) {
            if (width < n - height - 1 || width > n + height - 1)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}
