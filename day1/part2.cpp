#include <iostream>

int main() {
    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int count = 0;
    unsigned int pos = 50;
    char dir;
    unsigned int n;
    while (std::cin >> dir >> n) {
        // Working under the assumption I have clean input
        // Compiler will shrink this to one equation
        // Cannot use div as not unsigned overload
        const unsigned int quot = n / 100;
        const unsigned int rem = n % 100;
        count += quot;
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

