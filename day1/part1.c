#include <stdio.h>

int main() {
    unsigned int count = 0;
    unsigned char pos = 50;
    char dir;
    unsigned int n;
    while (scanf("%c%u\n", &dir, &n) != EOF) {
        // Working under the assumption I have clean input
        n %= 100;
        switch (dir) {
            case 'R':
                pos += n;
                if (pos >= 100) {
                    pos -= 100;
                }
                break;
            case 'L':
                if (pos < n) {
                    pos += 100;
                }
                pos -= n;
        }
        count += pos == 0;
    }

    printf("%u\n", count);
}

