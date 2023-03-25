#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<size_t> primes;
array<bool, 1000001> primeFlags;
size_t n;

void generatePrimes() {
    primeFlags.fill(true);
    primes.reserve(primeFlags.size());
    primeFlags[0] = false;
    primeFlags[1] = false;
    for (size_t i = 2; i < primeFlags.size(); i++)
        if (primeFlags[i])
            for (size_t j = 2 * i; j < primeFlags.size(); j += i)
                primeFlags[j] = false;
    for (size_t i = 2; i < primeFlags.size(); i++)
        if (primeFlags[i]) primes.push_back(i);
}

size_t repeatGoldbach() {
    for (const size_t& prime : primes)
        if (primeFlags[n - prime]) return n - 2 * prime;
    return 0;
}

int main() {
    generatePrimes();
    cin >> n;
    size_t counter = 0;
    while (n != 2 && n != 0) {
        n = repeatGoldbach();
        counter++;
    }
    cout << counter << endl;
    return 0;
}
