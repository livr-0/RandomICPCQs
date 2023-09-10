#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> input;
unordered_map<long, set<pair<long, long>>> islandGraph;
unordered_map<long, set<pair<long, long>>> biggerGraph;
unordered_map<long, long> islandUnion;
unordered_map<long, unordered_set<long>> islandUnionGrouped;
unordered_map<long, long> islandMSTValue;

long findBiggerMST() {
    unordered_set<long> visited;
    set<pair<long, pair<long, long>>> allEdges;
    unordered_map<long, long> components;
    long componentsCount = 0, MSTWeight = 0;
    for (const auto& edge : biggerGraph) {
        components[edge.first] = ++componentsCount;
        visited.insert(edge.first);
        for (const auto& target : edge.second)
            if (!visited.count(target.second))
                allEdges.insert({ target.first, { edge.first, target.second } });
    }
    for (const auto& edge : allEdges) {
        long weight = edge.first;
        long node1 = edge.second.first;
        long node2 = edge.second.second;
        if (components[node1] != components[node2]) {
            MSTWeight += weight;
            long pruneComponent = components[node2];
            for (auto& component : components)
                if (component.second == pruneComponent)
                    component.second = components[node1];
        }
    }
    return MSTWeight;
}

void findSmallerMST(int unionID) {
    unordered_set<long> visited;
    set<pair<long, pair<long, long>>> allEdges;
    unordered_map<long, long> components;
    long componentsCount = 0, MSTWeight = 0;
    for (const auto& trueNode : islandUnionGrouped[unionID]) {
        components[trueNode] = ++componentsCount;
        visited.insert(trueNode);
        for (const auto& edge : islandGraph[trueNode])
            if (!visited.count(edge.second))
                allEdges.insert({edge.first, { trueNode, edge.second }});
    }
    for (const auto& edge : allEdges) {
        long weight = edge.first;
        long node1 = edge.second.first;
        long node2 = edge.second.second;
        if (components[node1] != components[node2]) {
            MSTWeight += weight;
            long pruneComponent = components[node2];
            for (auto& component : components)
                if (component.second == pruneComponent)
                    component.second = components[node1];
        }
    }
    islandMSTValue[unionID] = MSTWeight;
}

void islandUnionDFS(int current, int unionId) {
    islandUnion[current] = unionId;
    islandUnionGrouped[unionId].insert(current);
    for (const pair<long, long>& edge : islandGraph[current]) {
        int child = edge.second;
        if (!islandUnion[child]) islandUnionDFS(child, unionId);
    }
}

void makeIslandUnions(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!islandUnion[i]) {
            count++;
            int unionId = n + count;
            islandUnionDFS(i, unionId);
        }
    }
}

void makeBiggerGraph(int n) {
    for (int i = 2; i <= n; i++) {
        int ti = i - 2;
        for (int j = 1; j < i; j++) {
            int tj = j - 1;
            if (input[ti][tj] > 0) {
                long iID = islandUnion[i];
                long jID = islandUnion[j];
                long x = input[ti][tj] + islandMSTValue[iID] + islandMSTValue[jID];
                biggerGraph[iID].insert({ x, jID });
                biggerGraph[jID].insert({ x, iID });
            }
        }
    }

    for (const auto& id : islandUnionGrouped) {
        unordered_map<long, long> shrink;
        for (const auto& edge : biggerGraph[id.first]) {
            if (!shrink.count(edge.second)) shrink[edge.second] = edge.first;
            else shrink[edge.second] = min(shrink[edge.second], edge.first);
        }
        set<pair<long, long>> newEdges;
        for (const auto& edge : shrink)
            newEdges.insert({ edge.second, edge.first });
        biggerGraph[id.first] = newEdges;
    }
}

void connectivityCheckDFS(long current, unordered_set<long>& islandsVisited) {
    islandsVisited.insert(current);
    for (auto& edge : biggerGraph[current])
        if (!islandsVisited.count(edge.second))
            connectivityCheckDFS(edge.second, islandsVisited);
}

bool checkConnectivity() {
    unordered_set<long> islandsVisited;
    connectivityCheckDFS((*biggerGraph.begin()).first, islandsVisited);
    return (islandsVisited.size() == biggerGraph.size());
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        vector<int> inputLine;
        for (int j = 1; j < i; j++) {
            long x;
            cin >> x;
            inputLine.push_back(x);
            if (x < 0) {
                x = -x;
                islandGraph[i].insert({x, j});
                islandGraph[j].insert({x, i});
            }
        }
        input.push_back(inputLine);
    }
    makeIslandUnions(n);
    for (const auto& id : islandUnionGrouped) findSmallerMST(id.first);
    makeBiggerGraph(n);
    if (!checkConnectivity()) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << findBiggerMST() << endl;
    return 0;
}
