#include <algorithm>
#include <iostream>
#include <vector>

size_t common_prefix(const std::string& a, const std::string& b) {
    size_t common_size = std::min(a.size(), b.size());
    for (size_t i = 0; i < common_size; i++) {
        if (a[i] != b[i]) {
            return i;
        }
    }
    return common_size;
}

int main() {
    // Read inputs
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> alice, bob;
    alice.reserve(n);
    bob.reserve(m);

    for (size_t i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        alice.push_back(word);
    }

    for (size_t i = 0; i < m; i++) {
        std::string word;
        std::cin >> word;
        bob.push_back(word);
    }

    // Solve problem
    size_t sum = 0;
    for (const std::string& target : alice) {
        // Build frequency table of common prefixes
        std::vector<size_t> prefixes(target.size() + 1, 0);
        for (const std::string& word : bob) {
            prefixes[common_prefix(target, word)]++;
        }
        // Calculate number of possible moves
        size_t moves = 0, required = 0;
        for (size_t i = 1; i <= target.size(); i++) {
            required++;
            size_t to_move = std::min(required, prefixes[i]);
            required -= to_move;
            moves += to_move;
        }
        sum += moves;
    }

    std::cout << sum << std::endl;

    return 0;
}
