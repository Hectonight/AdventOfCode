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

        char d1 = '0';
        char d2 = '0';
        char curr;
        std::cin.get(curr);
        while (curr != '\n') {
            d1 = d2;
            d2 = curr;
            std::cin.get(curr);
        }

        const unsigned int n = 10 * (d1 - '0') + (d2 - '0');
        if (dir == 'R') {
            pos += n;
            if (pos >= 100) {
                pos -= 100;
            }
        } else {
            if (pos < n) {
                pos += 100;
            }
            pos -= n;
        }
        count += pos == 0;
    }

    std::cout << count << '\n';
}

