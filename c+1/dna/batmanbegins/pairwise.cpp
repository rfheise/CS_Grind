#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();
    long long first = 0;
    long long second = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > second) {
            if (numbers[i] > first) {
                first = numbers[i];
            } else {
                second = numbers[i];
            }
        }
    }

    return first * second;
}

int main() {
    short n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
