#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Tile {
    int x1, y1, x2, y2;
};

struct Point {
    int x, y;
};

auto find_tile(vector<Tile> &tiles, Point column) {
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        auto &tile = *it;
        if (tile.x1 <= column.x && tile.x2 >= column.x && tile.y1 <= column.y && tile.y2 >= column.y) {
            return it;
        }
    }

    return tiles.end();
}

int main() {
    int side_length, column_count;
    vector<Tile> tiles;

    cin >> side_length >> column_count;

    // Start with one big tile
    tiles.push_back({ 0, 0, side_length - 1, side_length - 1});

    for (int i = 0; i < column_count; i++) {
        int x, y;
        cin >> x >> y;
        Point col { x, y };

        auto tile_it = find_tile(tiles, col);
        if (tile_it == tiles.end()) {
            cerr << "fuck\n";
            return 1;
        }
        auto &tile = *tile_it;

        vector<Tile> new_tiles;

        if (x > tile.x1) {
            new_tiles.push_back({ tile.x1, tile.y1, x - 1, tile.y2 });
        }
        if (x < tile.x2) {
            new_tiles.push_back({ x + 1, tile.y1, tile.x2, tile.y2 });
        }
        if (y > tile.y1) {
            new_tiles.push_back({ x, tile.y1, x, y - 1 });
        }
        if (y < tile.y2) {
            new_tiles.push_back({ x, y + 1, x, tile.y2 });
        }

        tiles.erase(tile_it);
        tiles.insert(tiles.end(), new_tiles.begin(), new_tiles.end());
    }

    cout << tiles.size() << endl;
    for (const auto &tile : tiles) {
        cout << tile.x1 << ' ' << tile.y1 << ' ' << (tile.x2 - tile.x1 + 1) << ' ' << (tile.y2 - tile.y1 + 1) << endl;
    }
}
