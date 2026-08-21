#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int count = 0;
    unsigned char pos = 50;
    char dir;
    unsigned int n;
    while (scanf("%c%u\n", &dir, &n) != EOF) {
        // Working under the assumption I have clean input
        const div_t d = div(n, 100);
        count += d.quot;
        switch (dir) {
            case 'R':
                pos += d.rem;
                if (pos >= 100) {
                    ++count;
                    pos -= 100;
                }
                break;
            case 'L':
                if (pos < d.rem) {
                    count += pos != 0;
                    pos += 100;
                }
                pos -= d.rem;
                count += pos == 0;
        }
    }

    printf("%u\n", count);
}

