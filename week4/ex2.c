#include <zconf.h>

/*
 * With 3 forks finally 8 processes are created:
 * ├─ex2─┬─ex2─┬─ex2───ex2
 * │     │     └─ex2
 * │     ├─ex2───ex2
 * │     └─ex2
 *
 * With 5 forks - 32 processes
 *
 * This is because after each fork all existing processes duplicate themselves
 * Finally 2^(forks quantity) processes are created
 */

int main() {
    int i;
    for(i = 0; i < 5; i++) {
        fork();
    }

    sleep(5);
    return 0;
}
