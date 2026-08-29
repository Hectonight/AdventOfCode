

#include <iostream>

// Code assumes newline is at the end of file

int main() {
    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int total = 0;
    char d;

    char first = 0;
    char second = 0;


    while (std::cin.get(d)) {
        if (d == '\n') {
            total += 10 * (first - '0') + second - '0';
            first = 0;
            second = 0;
        } else if (second > first) {
            first = second;
            second = d;
        } else if (d > second) {
            second = d;
        }
    }
    std::cout << total << '\n';


}
