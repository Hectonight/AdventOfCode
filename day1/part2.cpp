#include <iostream>

int main() {
    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int count = 0;
    unsigned int pos = 50;
    char dir;
    while (std::cin.get(dir)) {
        // Working under the assumption I have clean input

        unsigned int hundreds = 0;
        unsigned int rem = 0;

        char d1, d2;

        std::cin.get(d1);
        std::cin.get(d2);
        if (d2 == '\n') {
            rem = d1 - '0';
        } else {
            char curr;
            std::cin.get(curr);
            while (curr != '\n') {
                hundreds = 10 * hundreds + d1 - '0';
                d1 = d2;
                d2 = curr;
                std::cin.get(curr);
            }
            rem = 10 * (d1 - '0') + d2 - '0';
        }

        count += hundreds;
        if (dir == 'R') {
            pos += rem;
            if (pos >= 100) {
                ++count;
                pos -= 100;
            }
        } else {
            if (pos < rem) {
                count += pos != 0;
                pos += 100;
            }
            pos -= rem;
            count += pos == 0;
        }
    }

    std::cout << count << '\n';
}

