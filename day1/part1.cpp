#include <iostream>

int main() {
    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int count = 0;
    unsigned char pos = 50;
    char dir;
    unsigned int n;
    while (std::cin >> dir >> n) {
        // Working under the assumption I have clean input
        n %= 100;
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

