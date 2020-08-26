#include <stdio.h>

int main()
{
    char string[1000];
    printf("Waiting for string input: ");
    scanf("%s", string);

    int len = strlen(string), i;
    char result[len+1];
    result[len] = '\0';

    for (i = 1; i <= len; i++) {
        result[i-1] = string[len-i];
    }

    printf("Resulting string is: %s\n", result);
    return 0;
}
