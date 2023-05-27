// up down right

#include <cstddef>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<size_t, size_t> coord; // { x, y }

size_t n;
coord goal, botPos;
vector<vector<bool>> grid(100, vector<bool>(100));

void moveUp() {
    botPos.second--;
    coord somePos = botPos;
    if (grid[somePos.second][somePos.first]) {
        while (grid[somePos.second][somePos.first])
            somePos.second--;
        grid[botPos.second][botPos.first] = 0;
        if (somePos == goal) n--;
        else grid[somePos.second][somePos.first] = 1;
    }
    cout << "down" << endl;
}

void moveDown() {
    botPos.second++;
    coord somePos = botPos;
    if (grid[somePos.second][somePos.first]) {
        while (grid[somePos.second][somePos.first])
            somePos.second++;
        grid[botPos.second][botPos.first] = 0;
        if (somePos == goal) n--;
        else grid[somePos.second][somePos.first] = 1;
    }
    cout << "up" << endl;
}

void moveLeft() {
    botPos.first--;
    coord somePos = botPos;
    if (grid[somePos.second][somePos.first]) {
        while (grid[somePos.second][somePos.first])
            somePos.first--;
        grid[botPos.second][botPos.first] = 0;
        if (somePos == goal) n--;
        else grid[somePos.second][somePos.first] = 1;
    }
    cout << "left" << endl;
}

void moveRight() {
    botPos.first++;
    coord somePos = botPos;
    if (grid[somePos.second][somePos.first]) {
        while (grid[somePos.second][somePos.first])
            somePos.first++;
        grid[botPos.second][botPos.first] = 0;
        if (somePos == goal) n--;
        else grid[somePos.second][somePos.first] = 1;
    }
    cout << "right" << endl;
}

coord findSomeScooter() {
    for (size_t y = 0; y < grid.size(); y++) {
        for (size_t x = 0; x < grid[0].size(); x++) {
            if (grid[y][x]) {
                return { x, y };
            }
        }
    }
    return { 200, 200 };
}

void goThereX(coord targetPos) {
    while (botPos.first < targetPos.first) moveRight();
    while (botPos.first > targetPos.first) moveLeft();
    while (botPos.second < targetPos.second) moveDown();
    while (botPos.second > targetPos.second) moveUp();
}

void goThereY(coord targetPos) {
    while (botPos.second < targetPos.second) moveDown();
    while (botPos.second > targetPos.second) moveUp();
    while (botPos.first < targetPos.first) moveRight();
    while (botPos.first > targetPos.first) moveLeft();
}

int main() {
    cin >> n;
    cin >> botPos.first >> botPos.second >> goal.first >> goal.second;
    botPos.first += 30; botPos.second += 30; goal.first += 30; goal.second += 30;
    for (size_t i = 0; i < n; i++) {
        size_t x, y;
        cin >> x >> y;
        grid[y + 30][x + 30] = 1;
    }
    while (n) {
        coord targetScooter = findSomeScooter();
        if (targetScooter.first != goal.first) {
            if (targetScooter.second == botPos.second) moveDown();
            coord targetPosition;
            targetPosition.second = targetScooter.second;
            if (targetScooter.first > goal.first) targetPosition.first = targetScooter.first + 1;
            else targetPosition.first = targetScooter.first - 1;
            goThereX(targetPosition);
            if (targetScooter.first > goal.first) targetPosition.first = goal.first + 1;
            else targetPosition.first = goal.first - 1;
            goThereX(targetPosition);
        }
        if (targetScooter.second != goal.second) {
            if (targetScooter.first == botPos.first) moveRight();
            coord targetPosition;
            targetPosition.first = targetScooter.first;
            if (targetScooter.second > goal.second) targetPosition.second = targetScooter.second + 1;
            else targetPosition.second = targetScooter.second - 1;
            goThereY(targetPosition);
            if (targetScooter.second > goal.second) targetPosition.second = goal.second + 1;
            else targetPosition.second = goal.second - 1;
            goThereY(targetPosition);
        }
    }
    return 0;
}
