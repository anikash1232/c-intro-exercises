// PID: 730761368
// I pledge the COMP211 honor code.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    int in_string = 0;   // inside double-quoted string?
    int in_comment = 0;  // currently stripping a #... EOL comment?

    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (c == '\n') {
                putchar('\n');
                in_comment = 0;
            }
            continue; // suppress everything until newline
        }

        if (c == '"') {
            in_string = !in_string;
            putchar(c);
            continue;
        }

        if (!in_string && c == '#') {
            in_comment = 1; // start stripping until end of line
            continue;
        }

        putchar(c);
    }

    return EXIT_SUCCESS;
}
