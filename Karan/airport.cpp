#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<long long, long long> coords;

vector<coords> vertices;
double res = 0.0;

void getInput() {
  size_t n;
  cin >> n;
  while (n-- > 0) {
    long long x, y;
    cin >> x >> y;
    vertices.push_back({x, y});
  }
}

// Calculates length of longest line that can be drawn entirely
// inside the polygon which goes through both ith and jth vertices
void getLength(int i, int j) {
  const coords& v1 = vertices[i], v2 = vertices[j];
  // TODO: Check if line can be drawn  from v1 to v2 without breaking the polygon
  double l = sqrt(pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2));
  // TODO: Check if line can be extended beyond v1 and/or v2
  if (l > res) res = l;
}

int main() {
  getInput();
  for (size_t i = 0; i < vertices.size() - 1; i++)
    for (size_t j = i + 1; j < vertices.size(); j++)
      getLength(i, j);
  printf("Result: %.10f\n", res);
  return 0;
}
