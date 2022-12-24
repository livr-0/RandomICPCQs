#include <iostream>
#include <tuple>
#include <utility>

// Notes:
// - Occurences in the nth string are the occurences from strings n-1 and n-2, plus
//   any extra occurences in the overlap.
// - Once the length of both strings is >= |pattern|
//     - Prefixes are always the same
//     - Suffixes alternate each step
// - Since prefixes and suffixes are consistent in this way, the overlap counts can be precomputed.
// - Only two overlap counts are necessary

// Expected Output:
// Case 1: 5
// Case 2: 8
// Case 3: 4
// Case 4: 4
// Case 5: 7540113804746346428

std::tuple<std::string, std::string, uint64_t> starting_words(int l) {
	std::string a = "0", b = "1";
    uint64_t i = 0;
	while (a.size() < l) {
        std::swap(a, b);
        b = a + b;
        i++;
	}
	return std::tuple(a, b, i);
}

uint64_t count(std::string haystack, std::string needle) {
    uint64_t count = 0;
    size_t pos = 0;
    while (true) {
        size_t next = haystack.find(needle, pos);
        if (next == std::string::npos) {
            return count;
        }
        count++;
        pos = next + 1;
    }
}

uint64_t solve(int n, std::string p) {
    // Find the first two words at least as long as p
	auto [a, b, step] = starting_words(p.size());
    // If they occur after the nth word, p can't appear by the nth word
    if (step > n) {
        return 0;
    }

    // Count occurrences of p in those words
    uint64_t ca = count(a, p);
    uint64_t cb = count(b, p);
    // Count the occurrences of p in the overlaps that form each iteration
    uint64_t coa = count(a.substr(a.size() - p.size() + 1) + b.substr(0, p.size() - 1), p);
    uint64_t cob = count(b.substr(b.size() - p.size() + 1) + a.substr(0, p.size() - 1), p);

    // Iterate until n, calculating the number of occurrences at each step
    bool next_a = false;
    while (step < n) {
        step++;
        std::swap(ca, cb);
        cb += ca + (next_a ? coa : cob);
        next_a = !next_a;
    }

    return ca;
}

int main() {
	int n, i = 0;
	std::string p;
	while (i++, std::cin >> n >> p) {
		std::cout << "Case " << i << ": " << solve(n, p) << "\n";
	}
}
