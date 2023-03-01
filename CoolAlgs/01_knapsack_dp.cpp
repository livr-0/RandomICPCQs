#include <iostream>
#include <vector>

using namespace std;

// params: number of items, capacity, weights, values
// return: max value not exceeding capacity
size_t knapsack(size_t N, size_t C, vector<size_t>& W, vector<size_t>& V) {
    // initialising grid with dimensions N+1 by C+1 (values default to 0)
    vector<vector<size_t>> dp(N + 1, vector<size_t>(C + 1));

    // for each item i from 1 to N and for each weight j from 1 to C
    // determine max value obtainable by including/excluding the item
    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= C; j++)
            if (W[i] > j || dp[i-1][j] > dp[i-1][j-W[i]] + V[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j-W[i]] + V[i];

    return dp[N][C];
}

int main() {
    size_t n = 4, c = 10;
    vector<size_t> w = {3, 3, 5, 6}, v = {1, 4, 8, 5};
    cout << "Knapsacked: " << knapsack(n, c, w, v) << endl;
    return 0;
}
