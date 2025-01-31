#include <iostream>
#include <chrono>
#include <cstdint>
#include <vector>
#include <climits>

class LCG {
public:
    LCG(uint32_t seed, uint32_t a = 1664525, uint32_t c = 1013904223, uint32_t m = 1U << 31)
        : value(seed), a(a), c(c), m(m) {}

    uint32_t next() {
        value = (uint64_t(a) * value + c) % m; // Use 64-bit to prevent overflow
        return value;
    }

private:
    uint32_t value, a, c, m;
};

int max_subarray_sum(int n, uint32_t seed, int min_val, int max_val) {
    LCG lcg(seed);
    std::vector<int> random_numbers(n);

    for (int i = 0; i < n; ++i) {
        random_numbers[i] = lcg.next() % (max_val - min_val + 1) + min_val;
    }

    int max_sum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += random_numbers[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    return max_sum;
}

int64_t total_max_subarray_sum(int n, uint32_t initial_seed, int min_val, int max_val) {
    int64_t total_sum = 0;
    LCG lcg(initial_seed);

    for (int i = 0; i < 20; ++i) {
        uint32_t seed = lcg.next();
        total_sum += max_subarray_sum(n, seed, min_val, max_val);
    }

    return total_sum;
}

int main() {
    const int n = 10000;
    const uint32_t initial_seed = 42;
    const int min_val = -10;
    const int max_val = 10;

    auto start_time = std::chrono::high_resolution_clock::now();

    int64_t result = total_max_subarray_sum(n, initial_seed, min_val, max_val);

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Total Maximum Subarray Sum (20 runs): " << result << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
