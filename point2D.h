#ifndef FIELDNAVIGATOR_POINT2D_H
#define FIELDNAVIGATOR_POINT2D_H

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

using point2d = std::array<double, 2>;

inline point2d operator+(const point2d a, const point2d b) {
    return {a[0] + b[0], a[1] + b[1]};
}

inline point2d operator*(const point2d a, const double b) {
    return {a[0] * b, a[1] * b};
}

inline point2d operator-(const point2d a, const point2d b) {
    return a + (b * -1.0);
}

inline point2d operator%(const point2d a, const point2d b) {
    return {a[0] * b[0], a[1] * b[1]};
}

inline double operator*(const point2d a, const point2d b) {
    auto r = a % b;
    return std::accumulate(r.begin(), r.end(), 0.0);
}

inline double length(const point2d a) {
    return std::sqrt(a * a);
}

inline double distance(const point2d a, const point2d b) {
    return length(a - b);
}

inline double dot(const point2d a, const point2d b) {
    return a[0] * b[0] + a[1] * b[1];
}

inline std::ostream &operator<<(std::ostream &o, const point2d a) {
    o << "("<< a[0] << ", " << a[1] << ")";
    return o;
}

#endif //FIELDNAVIGATOR_POINT2D_H
