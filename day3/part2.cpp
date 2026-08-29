

#include <array>
#include <cstdint>
#include <iostream>

#define BATTERIES 12


template <size_t N>
constexpr std::array<uint64_t,N> generate_pow() {
    std::array<uint64_t,N> powers{1};

    for (size_t i = 1; i < N; ++i) {
        powers[i] = powers[i-1] * 10;
    }
    return powers;
}


// Generated at compile time
constexpr std::array<uint64_t,BATTERIES> POW = generate_pow<BATTERIES>();



// Code assumes newline is at the end of file
int main() {
    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t total = 0;
    char d;

    std::array<char, BATTERIES> digits{};




    // This is not a great solution for large BATTERIES
    // But in this case its only 12!
    while (std::cin.get(d)) {
        if (d == '\n') {

            for (size_t i = 0; i < BATTERIES; ++i) {
                total += (digits[i] - '0') * POW[BATTERIES - i - 1];
            }
            digits.fill(0);
        } else {
            bool moving = false;
            for (size_t i = 0; i < BATTERIES - 1; ++i) {
                if (digits[i] < digits[i + 1] || moving) {
                    digits[i] = digits[i + 1];
                    moving = true;
                }
            }
            if (digits[BATTERIES - 1] < d || moving) {
                digits[BATTERIES - 1] = d;
            }
        }
    }
    std::cout << total << '\n';


}
