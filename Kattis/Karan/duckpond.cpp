#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode {
    LinkedListNode *next, *previous;
    int payload;

    LinkedListNode(int aPayload): payload(aPayload), next(nullptr), previous(nullptr) {}

    LinkedListNode* insert(int aPayload) {
        LinkedListNode *newNode = new LinkedListNode(aPayload);
        newNode->previous = this;
        next = newNode;
        return newNode;
    }

    LinkedListNode* insert_final(int aPayload) {
        LinkedListNode *newNode = insert(aPayload);
        LinkedListNode *initialNode = this;
        while (initialNode->previous != nullptr) initialNode = initialNode->previous;
        newNode->next = initialNode;
        initialNode->previous = newNode;
        return initialNode;
    }

    pair<LinkedListNode*, int> eat(int steps) {
        if (steps != 0) return next->eat(--steps);
        if (next == this) return { nullptr, payload };
        previous->next = next;
        next->previous = previous;
        return { next, payload };
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> result(n);
    LinkedListNode *node = new LinkedListNode(1);

    for (int i = 2; i <= n; i++)
        if (i != n) node = node->insert(i);
        else node = node->insert_final(i);

    int counter = 1;
    while (node != nullptr) {
        pair<LinkedListNode*, int> q = node->eat(m - 1);
        node = q.first;
        result[q.second - 1] = counter++;
    }

    for (int res : result) cout << res << " ";
    cout << endl;

    return 0;
}
