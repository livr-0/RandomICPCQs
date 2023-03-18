#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

typedef tuple<double, size_t, double> classThing; // < frequency, count, length >

const char seasons[] = { 's', 'c', 'r', 'f' };
vector<size_t> factorials;
unordered_map<char, double> frequencies;
vector<classThing> classes;
int n;

void generateFactorials() {
    factorials.push_back(1);
    size_t res = 1;
    for (size_t i = 1; i <= 20; i++) {
        res *= i;
        factorials.push_back(res);
    }
}

void huffman() {
    priority_queue<classThing, vector<classThing>, greater<classThing>> pq;
    for (const auto& classs : classes) pq.push(classs);
    while (pq.size() > 1) {
        classThing ct = pq.top();
        pq.pop();
        size_t something = get<1>(ct) / 2;
        if (something) pq.push({ get<0>(ct)*2, something, get<2>(ct) + 1 });
        if (get<1>(ct) % 2 != 0) {
            classThing ct2 = pq.top();
            pq.pop();
            if(get<1>(ct2) - 1) pq.push({ get<0>(ct2), get<1>(ct2) - 1, get<2>(ct2) });
            pq.push({ get<0>(ct) + get<0>(ct2), 1, (get<0>(ct)*get<2>(ct) + get<0>(ct2)*get<2>(ct2)) / (get<0>(ct) + get<0>(ct2)) + 1 });
        }
    }
    cout.precision(7);
    cout << fixed << get<2>(pq.top()) << endl;
}

void findClasses() {
    for (int s = 0; s <= n; s++) {
        for (int c = 0; c <= n - s; c++) {
            for (int r = 0; r <= n - (s + c); r++) {
                int f = n - (s + c + r);
                size_t classCount = factorials[n] / (factorials[s] * factorials[c] * factorials[r] * factorials[f]);
                double classFrequency = pow(frequencies['s'], s) * pow(frequencies['c'], c) * pow(frequencies['r'], r) * pow(frequencies['f'], f);
                classes.push_back({ classFrequency, classCount, 0 });
            }
        }
    }
}

void getInput() {
    cin >> n;
    for (const char& season : seasons) {
        double freq;
        cin >> freq;
        frequencies[season] = freq;
    }
}

int main() {
    generateFactorials();
    getInput();
    findClasses();
    huffman();
    return 0;
}