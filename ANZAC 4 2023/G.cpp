#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> probs;
    for (int i = 0; i < n; i++) {
        double p;
        cin >> p;
        probs.push_back(p);
    }

    sort(probs.rbegin(), probs.rend());

    vector<double> scores(2 * n + 3, 0.0);
    scores[n + 1] = 1.0;
    double max_prob = 0.0;
    int range = 1;
    for (const double p : probs) {
        vector<double> new_scores(2 * n + 3, 0.0);
        double pass = 0.0;
        for (int i = -range; i <= range; i += 2) {
            new_scores[n + i + 1] = scores[n + i] * p + scores[n + i + 2] * (1 - p);
            if (i >= k) {
                pass += new_scores[n + i + 1];
            }
        }
        if (pass > max_prob) { max_prob = pass; }
        scores = new_scores;
        range++;
    }
    cout << max_prob << endl;
}