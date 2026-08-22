#include <iostream>
#include <cstdint>
#include <array>
#include <algorithm>

#define MAX_DIGITS 20

/**
 * This function builds a lookup table of powers of 10 at compile time for O(1) lookup in practice.
 * @return A lookup table of powers of 10
 */
constexpr std::array<uint64_t, MAX_DIGITS> buildPower10() {
    uint64_t result = 1;
    std::array<uint64_t, MAX_DIGITS> powers{};
    for (size_t i = 0; i < MAX_DIGITS; i++) {
        powers[i] = result;
        result *= 10;
    }
    return powers;
}


static const u_char CHECKS[] = {1,2,3,5,7};
static constexpr std::array<uint64_t, MAX_DIGITS> POW10 = buildPower10();



/**
 * Floor or base 10 logarithm of n plus 1
 * If n is 0 behavior is undefined
 * Binary search of compiler time created power lookup table
 * Depending on inputs linear serach may be better
 * @return floor(log10(n)) + 1
 */
uint64_t ilog10p1(uint64_t n) {
    return std::upper_bound(POW10.begin(), POW10.end(), n) - POW10.begin();
}


bool already_checked(uint64_t num, const size_t check_idx) {
    for (size_t i = 0; i < check_idx; i++) {

        uint64_t n = num;
        const uint64_t power = POW10[CHECKS[i]];
        const uint64_t first = n % power;
        n /= power;

        while (n > 0) {
            const uint64_t curr = n % power;
            n /= power;
            if (curr != first) {
                goto fail;
            }
        }
        return true;
        fail:;
    }
    return false;
}


uint64_t builder(uint64_t base, uint64_t power, u_char count) {
    uint64_t adder = base;
    uint64_t result = 0;
    for (u_char i = 0; i < count; i++) {
        result += adder;
        adder *= power;
    }
    return result;
}

/**
 * Gets the next bad id INCLUSIVE OF n
 * Check is how many parts we split up the number into
 */
uint64_t next(uint64_t n, const uint64_t chunk) {
    if (n == 0) n = 1;
    const uint64_t d = ilog10p1(n);

    // Compiler should optimize to d & 1 == 1
    if (const uint64_t rem = d % chunk; rem != 0 || d == chunk) {
        size_t newd = d + chunk - rem;
        if (newd == chunk) {
            newd += chunk;
        }
        return builder(POW10[chunk-1], POW10[chunk], newd / chunk);
    }

    const uint64_t last = n / POW10[d - chunk];
    const uint64_t power = POW10[chunk];
    // std::cout << "n: " << n << '\n';
    // std::cout << "chunk: " << chunk << '\n';
    // std::cout << "last: " << last << '\n';

    bool go_up = false;
    while (n >= POW10[chunk]) {
        uint64_t curr = n % power;
        n /= power;
        go_up = last < curr || (last == curr && go_up);
    }

    const uint64_t base = go_up ? last+1 : last;
    return builder(base, power, d / chunk);

}



int main() {

    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t lower;
    uint64_t upper;
    uint64_t count = 0;

    while (std::cin >> lower
        && std::cin.ignore(1) // deal with dash
        && std::cin >> upper) {
        std::size_t check_idx = 0;
        for (u_char i = 1; i <= MAX_DIGITS/2; i++) {

            // Fail fast
            if (ilog10p1(upper) < i * 2) break;
            for (uint64_t x = next(lower, i); x <= upper; x = next(x+1, i)) {
                // std::cout << "x: " << x << '\n';
                // std::cout << "i: " << static_cast<uint64_t>(i) << '\n';

                // if (x == 2626262626) {
                //     std::cout << "i: " << i << '\n';
                //     std::cout << "check_idx: " << check_idx << '\n';
                //     std::cout << "lower: " << lower << '\n';
                //     std::cout << "upper: " << upper << '\n';
                //     std::cout << "already_checked(x, check_idx): " << already_checked(x, check_idx) << '\n';
                // }
                if (!already_checked(x, check_idx)) {
                    count += x;
                    // std::cout << x << '\n';
                }
                // std::cout << "next: " << next(x+1, i) << '\n';
            }
            check_idx += CHECKS[check_idx] == i;
        }
        std::cin.ignore(1); // Deal with comma
    }

    std::cout << count << '\n';
}

