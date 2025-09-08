// PID: 730761368
// I pledge the COMP211 honor code.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    int in_string = 0;
    int in_comment = 0;

    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (c == '\n') {
                putchar('\n');
                in_comment = 0;
            }
            continue;
        }

        if (c == '"') {
            in_string = !in_string;
            putchar(c);
            continue;
        }

        if (!in_string && c == '#') {
            in_comment = 1;
            continue;
        }

        putchar(c);
    }

    return EXIT_SUCCESS;
}
