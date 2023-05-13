#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const double eps = 1e-7;

typedef pair<int, int> coord;

struct Segment {
    coord point, vec;
    Segment(coord p1, coord p2) {
        point = p1;
        vec = coord(p2.first - p1.first, p2.second - p1.second);
    }
};

int id = 0;
struct Wire {
    int myId, utility;
    vector<coord> points;
    Wire(bool getInput = 0) {
        if (getInput) {
            myId = id++;
            cin >> utility;
            int n;
            cin >> n;
            while (n--) {
                coord point;
                cin >> point.first >> point.second;
                points.push_back(point);
            }
        }
    }
    bool operator<(const Wire& aOther) const { return myId < aOther.myId; }
};

map<Wire, set<Wire>> intersections;
vector<Wire> wires;

bool segmentsCollide(Wire& w1, Wire& w2) {
    for (int i = 0; i < w1.points.size() - 1; i++)
        for (int j = 0; j < w2.points.size() - 1; j++) {
            Segment a(w1.points[i], w1.points[i+1]), b(w2.points[j], w2.points[j+1]);
            coord diff = coord(b.point.first - a.point.first, b.point.second - a.point.second);
            double crossProd = a.vec.first * b.vec.second - a.vec.second * b.vec.first;
            if (abs(crossProd) <= eps) continue;
            double t = (diff.first * b.vec.second - diff.second * b.vec.first) / crossProd;
            double u = (diff.first * a.vec.second - diff.second * a.vec.first) / crossProd;
            if (t >= 0 && t <= 1 && u >= 0 && u <= 1) return true;
        }
    return false;
}

void makeIntersectionsMap() {
    for (int i = 0; i < wires.size() - 1; i++)
        for (int j = i + 1; j < wires.size(); j++) {
            Wire& w1 = wires[i], w2 = wires[j];
            if (w1.points[0].first < (*(--w2.points.end())).first && (*(--w1.points.end())).first > w2.points[0].first)
                if (
                    w1.points[0].first < w2.points[0].first && (*(--w1.points.end())).first < (*(--w2.points.end())).first ||
                    w2.points[0].first < w1.points[0].first && (*(--w2.points.end())).first < (*(--w1.points.end())).first ||
                    segmentsCollide(w1, w2)
                ) {
                    intersections[w1].insert(w2);
                    intersections[w2].insert(w1);
                }
        }
}

void doMatching() {
    if (intersections.empty()) {
        cout << 0 << endl;
        return;
    }
    set<Wire> visited;
    map<Wire, Wire> matches;
    for (const Wire& wire : wires)
        if (visited.count(wire) == 0) {
            visited.insert(wire);
            Wire bestMatch;
            int bestMatchUtility = -1;
            for (const Wire& otherWire : intersections[wire])
                if (otherWire.utility > bestMatchUtility) {
                    bestMatchUtility = otherWire.utility;
                    bestMatch = otherWire;
                }
            if (bestMatchUtility != -1) {
                if (visited.count(bestMatch) == 0) {
                    matches[bestMatch] = wire;
                    matches[wire] = bestMatch;
                    visited.insert(bestMatch);
                } else {
                    Wire theOtherOne = matches[bestMatch];
                    if (theOtherOne.utility < wire.utility) {
                        matches.erase(theOtherOne);
                        visited.erase(theOtherOne);
                        matches[wire] = bestMatch;
                        matches[bestMatch] = wire;
                    }
                }
            }
        }
    visited.clear();
    int res = 0;
    for (const pair<Wire, Wire>& match : matches)
        if (visited.count(match.first) == 0 && visited.count(match.second) == 0) {
            visited.insert(match.first);
            visited.insert(match.second);
            cout << match.first.myId << " " << match.second.myId << endl;
            res += match.first.utility + match.second.utility;
        }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) wires.push_back(Wire(1));
    makeIntersectionsMap();
    doMatching();
    return 0;
}
