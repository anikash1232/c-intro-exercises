// PID: 730761368
// I pledge the COMP211 honor code.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum { ALPHA = 26, MAX_HEIGHT = 10 };

static void process_input(int counts[ALPHA]) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            int idx = tolower(ch) - 'a';
            if (idx >= 0 && idx < ALPHA) {
                counts[idx]++;
            }
        }
    }
}

static int total_letters(const int counts[ALPHA]) {
    int total = 0;
    for (int i = 0; i < ALPHA; i++) {
        total += counts[i];
    }
    return total;
}

static int max_count(const int counts[ALPHA]) {
    int m = 0;
    for (int i = 0; i < ALPHA; i++) {
        if (counts[i] > m) {
            m = counts[i];
        }
    }
    return m;
}

static void print_counts(const int counts[ALPHA]) {
    puts("Counts:");
    for (int i = 0; i < ALPHA; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }
    putchar('\n');
}

static void print_percents(const int counts[ALPHA]) {
    puts("Percents:");
    int total = total_letters(counts);
    if (total > 0) {
        for (int i = 0; i < ALPHA; i++) {
            if (counts[i] > 0) {
                double pct = (counts[i] * 100.0) / (double)total;
                printf("%c: %.1f%%\n", 'a' + i, pct);
            }
        }
    }
    putchar('\n');
}

static void print_chart(const int counts[ALPHA]) {
    puts("Chart:");
    int maxc = max_count(counts);
    int heights[ALPHA];

    if (maxc == 0) {
        for (int i = 0; i < ALPHA; i++) {
            heights[i] = 0;
        }
    } else {
        for (int i = 0; i < ALPHA; i++) {
            heights[i] = (int)((counts[i] * 1.0 * MAX_HEIGHT) / (double)maxc);
        }
    }

    for (int row = MAX_HEIGHT; row >= 1; row--) {
        for (int i = 0; i < ALPHA; i++) {
            putchar(heights[i] >= row ? '|' : ' ');
        }
        putchar('\n');
    }

    for (int i = 0; i < ALPHA; i++) {
        putchar('a' + i);
    }
    putchar('\n');
}

int main(void) {
    int counts[ALPHA] = {0};

    process_input(counts);
    print_counts(counts);
    print_percents(counts);
    print_chart(counts);

    return EXIT_SUCCESS;
}
