#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    size_t n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    set<string> items, toErase;
    map<string, size_t> counter;
    vector<string> order;

    while (n1--) {
        string s;
        size_t c;
        cin >> s >> c;
        if (!counter.count(s)) order.push_back(s);
        counter[s] += c;
    }
    for (const auto& count : counter)
        if (count.second >= 20)
            items.insert(count.first);
    counter.clear();
    while (n2--) {
        string s;
        size_t c;
        cin >> s >> c;
        counter[s] += c;
    }
    for (const string& item : items)
        if (counter[item] < 20)
            toErase.insert(item);
    for (const string& erase : toErase)
        items.erase(erase);
    counter.clear();
    toErase.clear();
    while (n3--) {
        string s;
        size_t c;
        cin >> s >> c;
        counter[s] += c;
    }
    for (const string& item : items)
        if (counter[item] < 20)
            toErase.insert(item);
    for (const string& erase : toErase)
        items.erase(erase);
    cout << items.size() << " ";
    for (const string& item : order)
        if (items.count(item))
            cout << item << " ";
    cout << endl;
    return 0;
}
