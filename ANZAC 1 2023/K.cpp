#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    vector<int> A, B;

    for (size_t i = 0; i < n; i++) {
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    for (int i = n; i > 0; i--) {
        int c = 0;
        for (int j = 0; j < n; j++)
            if (i >= A[j] && i <= B[j])
                c++;
        if (i == c) {
            cout << i << endl;
            return 0;;
        }
    }

    cout << -1 << endl;
    return 0;
}
