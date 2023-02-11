#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int get_sign(double val) {
  if (fabs(val) < 1e-8) return 0;
  if (val < 0) return -1;
  return 1;
}

/* VECTOR ADT & OPERATIONS */
struct Vector { double x, y; };
Vector operator-(Vector v1, Vector v2) { return (Vector){v1.x - v2.x, v1.y - v2.y}; }
double dot_product(Vector v1, Vector v2) { return v1.x * v2.x + v1.y * v2.y; }
double cross_product(Vector v1, Vector v2) { return v1.x * v2.y - v1.y * v2.x; }
double vector_distance(Vector v1, Vector v2) { return sqrt(dot_product((v2 - v1), (v2 - v1))); }

/* LINE SEGMENT ADT & OPERATIONS */
struct LineSegment { Vector v1, v2; };
double dist_btw_segments(LineSegment l1, LineSegment l2) {
  double d1 = cross_product((l2.v1 - l1.v1), (l2.v2 - l1.v1));
  double d2 = cross_product((l2.v2 - l2.v1), (l1.v2 - l1.v1));
  return d1 / d2 * vector_distance(l1.v1, l1.v2);
}

/* INTERSECTION POINT ADT & OPERATIONS */
struct IntersectionPoint { double length; int flag; };
bool operator<(IntersectionPoint i1, IntersectionPoint i2) { return get_sign(i2.length - i1.length) > 0; }

int vertices_count; // STORES NUMBER OF VERTICES IN POLYGON
double res; // STORES LONGEST LINE SEGMENT
Vector polygon[205]; // STORES ALL VERTICES OF THE POLYGON

void get_length(LineSegment l) {
  IntersectionPoint isp[205];
  int intersections_count = 0;

  for (int i = 1; i <= vertices_count; ++i) {
    int d1 = get_sign(cross_product((l.v2 - l.v1), (polygon[i] - l.v1)));
    int d2 = get_sign(cross_product((l.v2 - l.v1), (polygon[i % vertices_count + 1] - l.v1)));
    if (d1 > d2) isp[++intersections_count] = (IntersectionPoint){dist_btw_segments(l, (LineSegment){polygon[i], polygon[i % vertices_count + 1]}), (d1 && d2) ? 2 : 1};
    else if (d1 < d2) isp[++intersections_count] = (IntersectionPoint){dist_btw_segments(l, (LineSegment){polygon[i], polygon[i % vertices_count + 1]}), (d1 && d2) ? -2 : -1};
  }

  sort(isp + 1, isp + intersections_count + 1);
  int flag = 0; double length = 0.0;
  for (int i = 1; i <= intersections_count; ++i) {
    if (flag) length += isp[i].length - isp[i - 1].length;
    else {
      if (get_sign(length - res) >= 0) res = length;
      length = 0.0;
    }
    flag += isp[i].flag;
  }

  if (get_sign(length - res) >= 0) res = length;
}

int main() {
  cin >> vertices_count;
  for (int i = 1; i <= vertices_count; ++i) {
    double x, y; cin >> x >> y;
    polygon[i].x = x; polygon[i].y = y;
  }

  for (int i = 1; i <= vertices_count; ++i)
    for (int j = i + 1; j <= vertices_count; ++j)
      get_length((LineSegment){polygon[i], polygon[j]});

  cout << fixed; cout.precision(10); cout << res << endl;
  return 0;
}
