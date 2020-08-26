#include <stdio.h>

int main() {
    printf("Waiting for two integers: ");
    int x, y;
    scanf("%d %d", &x, &y);
    int_swap(&x, &y);

    printf("After swap: %d %d", x, y);
    return 0;
}

void int_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
