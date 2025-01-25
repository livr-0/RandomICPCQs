#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct KeyMoves { int ui = -1, di = -1, lj = -1, rj = -1; };
struct BFSNode {
    int i, j, k, m;
    BFSNode(int ai, int aj, int ak, int am) { i = ai; j = aj; k = ak; m = am; }
};

int main() {
    int r, c;
    cin >> r >> c;

    // make keyboard
    vector<string> keyboard(r);
    for (int i = 0; i < r; i++) cin >> keyboard[i];

    string target;
    cin >> target;
    target += '*';

    // identify valid moves for each key
    vector<vector<KeyMoves>> keymoves(r, vector<KeyMoves>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            for (int ui = i - 1; ui >= 0; ui--)
                if (keyboard[i][j] != keyboard[ui][j]) {
                    keymoves[i][j].ui = ui;
                    break;
                }

            for (int di = i + 1; di < r; di++)
                if (keyboard[i][j] != keyboard[di][j]) {
                    keymoves[i][j].di = di;
                    break;
                }

            for (int lj = j - 1; lj >= 0; lj--)
                if (keyboard[i][j] != keyboard[i][lj]) {
                    keymoves[i][j].lj = lj;
                    break;
                }

            for (int rj = j + 1; rj < c; rj++)
                if (keyboard[i][j] != keyboard[i][rj]) {
                    keymoves[i][j].rj = rj;
                    break;
                }
        }

    // bfs
    vector<vector<vector<bool>>> seen(r, vector<vector<bool>>(c, vector<bool>(target.size(), false)));
    queue<BFSNode> frontier;
    frontier.push(BFSNode(0, 0, 0, 0));
    seen[0][0][0] = true;
    while (frontier.size()) {
        BFSNode& node = frontier.front();

        if (keyboard[node.i][node.j] == target[node.k]) {
            node.k++;
            if (node.k == target.length()) {
                cout << node.k + node.m << endl;
                return 0;
            }
        } else {
            KeyMoves& moves = keymoves[node.i][node.j];

            if (moves.ui != -1 && !seen[moves.ui][node.j][node.k]) {
                seen[moves.ui][node.j][node.k] = true;
                frontier.push(BFSNode(moves.ui, node.j, node.k, node.m + 1));
            }
            if (moves.di != -1 && !seen[moves.di][node.j][node.k]) {
                seen[moves.di][node.j][node.k] = true;
                frontier.push(BFSNode(moves.di, node.j, node.k, node.m + 1));
            }
            if (moves.lj != -1 && !seen[node.i][moves.lj][node.k]) {
                seen[node.i][moves.lj][node.k] = true;
                frontier.push(BFSNode(node.i, moves.lj, node.k, node.m + 1));
            }
            if (moves.rj != -1 && !seen[node.i][moves.rj][node.k]) {
                seen[node.i][moves.rj][node.k] = true;
                frontier.push(BFSNode(node.i, moves.rj, node.k, node.m + 1));
            }

            frontier.pop();
        }
    }

    return 0;
}
