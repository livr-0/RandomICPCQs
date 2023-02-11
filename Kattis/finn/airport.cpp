#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

struct Vec2 {
    long long x, y;

    Vec2 operator-(const Vec2 &other) const {
        return {x - other.x, y - other.y};
    }

    bool operator==(const Vec2 &other) const {
        return x == other.x && y == other.y;
    }

    double cross(const Vec2 &other) const {
        return x * other.y - y * other.x;
    }

    double dot(const Vec2 &other) const {
        return x * other.x + y * other.y;
    }

    double len() const {
        return std::sqrt(x * x + y * y);
    }

    friend std::ostream &operator<<(std::ostream &out, const Vec2 &vec) {
        return (out << "(" << vec.x << ", " << vec.y << ")");
    }
};

double raydist(const std::vector<Vec2> &points, const Vec2 &p, const Vec2 &pr) {
    Vec2 r = pr - p;
    //std::cout << "\nraydist(" << p << ", " << pr << ")\n";
    double closest = 1.0 / 0.0;
    for (size_t i = 0; i < points.size(); i++) {
        //std::cout << std::endl;
        //std::cout << "current: " << closest << std::endl;
        const Vec2 &q = points[i];
        const Vec2 &qs = points[(i + 1) % points.size()];
        //std::cout << "segment: " << q << ", " << qs << std::endl;

        Vec2 s = qs - q;
        //std::cout << "rs: " << r << ", " << s << std::endl;
        double cross = r.cross(s);
        if (cross == 0) {
            continue;
        }

        Vec2 offset = q - p;
        double t = offset.cross(s) / cross;
        double u = offset.cross(r) / cross;
        //std::cout << t << ", " << u << std::endl;

        if (t > 0 && t < closest && u > 0 && u < 1) {
            closest = t;
        }

        if (t > 0 && t < closest && u == 0) {
            const Vec2 &s0 = points[(i + points.size() - 1) % points.size()];
            //std::cout << "0: " << s0 << ", " << q << ", " << qs << std::endl;
            double cross1 = r.cross(s0 - p);
            double cross2 = r.cross(qs - p);
            //std::cout << cross1 << ", " << cross2 << std::endl;
            if (cross1 != 0 && std::signbit(cross1) != std::signbit(cross2)) {
                closest = t;
            } else if (cross1 == 0 && std::signbit(cross2) == std::signbit(r.dot(q - s0))) {
                closest = t;
            }
        }
        if (t > 0 && t < closest && u == 1) {
            const Vec2 &s3 = points[(i + 2) % points.size()];
            //std::cout << "1: " << s1 << ", " << s2 << ", " << s3 << std::endl;
            double cross1 = r.cross(q - p);
            double cross2 = r.cross(s3 - p);
            //std::cout << cross1 << ", " << cross2 << std::endl;
            if (cross2 != 0 && std::signbit(cross1) != std::signbit(cross2)) {
                closest = t;
            } else if (cross2 == 0 && std::signbit(cross1) == std::signbit(r.dot(s3 - qs))) {
                closest = t;
            }
        }
    }
    //std::cout << closest << std::endl;
    return closest * r.len();
}

int main() {
    std::cout.precision(17);

    size_t count;
    std::cin >> count;

    std::vector<Vec2> points;
    points.reserve(count);

    for (size_t i = 0; i < count; i++) {
        long long x, y;
        std::cin >> x >> y;
        points.push_back({x, y});
    }

    double maximum = 0.0;
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            const Vec2 &a = points[i];
            const Vec2 &b = points[j];
            double dist1 = raydist(points, a, b);
            double dist2 = raydist(points, b, a);
            //std::cout << dist1 << ", " << dist2 << std::endl;
            if (dist1 == 1.0 / 0.0 && dist2 == 1.0 / 0.0) {
                continue; 
            }
            if (dist1 == 1.0 / 0.0 && dist2 > maximum) {
                maximum = dist2;
            }
            if (dist2 == 1.0 / 0.0 && dist1 > maximum) {
                maximum = dist1;
            }
            double dist = dist1 + dist2 - (a - b).len();
            if (dist > maximum && dist != 1.0 / 0.0) {
                //std::cout << a << ", " << b << std::endl;
                //std::cout << "updating to " << dist << std::endl;
                maximum = dist;
            }
        }
    }

    std::cout << maximum << "\n";
}
