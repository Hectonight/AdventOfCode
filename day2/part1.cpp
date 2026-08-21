#include <iostream>
#include <cstdint>

/**
 * Floor or base 10 logarithm of n plus 1
 * If n is 0 behavior is undefined
 * @return floor(log10(n)) + 1
 */
std::uint64_t ilog10p1(std::uint64_t n) {
    // Multiplication is faster than division, so we will go up instead of down.
    // Linear search should be good enough for the values we are working with.
    // Although Binary search has better complexity, runtime performance will most likely perform worse
    // for this as there are only 32 possible values.
    // It also may be wise to hardcode 32 individual values if we are going for
    // maximum performance so the CPU can use branch predictions more effectively
    // (similar linear runtime with comparisons rather than multiplication).
    // Though most slowdown will likely be reading in the input.
    std::uint64_t i = 0;
    std::uint64_t x = 1;
    while (x <= n) {
        x *= 10;
        i++;
    }
    return i;
}

std::uint64_t pow(std::uint64_t n, std::uint64_t p) {
    std::uint64_t result = 1;
    for (std::uint64_t i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}


/**
 * Gets the next bad id INCLUSIVE OF n
 */
std::uint64_t next(const std::uint64_t n) {
    /* The Plan
     * hardcode 0 -> 11
     * d = num of digis = floor(log(n))+1
     * If d is odd {
     *  return 10^d + 10^(d/2)
     * }
     *
     * first_half = first d/2 digits
     * second_half = second d/2 digits
     *
     * if second_half > first_half {
     *  return first_half+1|first_half+1
     * }
     * return first_half|first_half
     *
     *
    */

    if (n == 0) return 11;

    const std::uint64_t d = ilog10p1(n);
    const std::uint64_t pow10d2 = pow(10, d/2);

    // Compiler should optimize to d & 1 == 1
    if (d % 2 == 1) {
        return pow10d2 * pow10d2 * 10 + pow10d2;
    }

    // Compiler is smart enough to just use divmod
    const std::uint64_t first_half = n / pow10d2;
    if (n % pow10d2 > first_half) {
        return (first_half + 1) * pow10d2 + first_half + 1;
    }
    return first_half * pow10d2 + first_half;
}



int main() {

    // Making cout and cin faster or comparable to printf and scanf
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint64_t lower;
    std::uint64_t upper;
    std::uint64_t count = 0;

    while (std::cin >> lower
        && std::cin.ignore(1) // deal with dash
        && std::cin >> upper) {

        for (std::uint64_t x = next(lower); x <= upper; x = next(x+1)) {
            count += x;
        }
        std::cin.ignore(1);
    }
    std::cout << count << '\n';
}

