#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6, PI = acos(-1.0);

int sgn(double x) {
  return (x > EPS) - (x < -EPS);
}

double sqr(double x) {
  return x * x;
}

struct Point {
  double x, y, z;
  Point() {}
  Point(double x, double y, double z): x(x), y(y), z(z) {}
  bool input() {
    double lat, lon;
    if (cin >> lat >> lon) {
      lat *= PI / 180;
      lon *= PI / 180;
      x = cos(lat) * cos(lon);
      y = cos(lat) * sin(lon);
      z = sin(lat);
//	  cerr << x << ' ' << y << ' ' << z << endl;
      return true;
    }
    return false;
  }
  friend Point operator*(Point a, Point b) {
    return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - b.x * a.y);
  }
  friend Point operator*(Point a, double k) {
    return Point(a.x * k, a.y * k, a.z * k);
  }
  friend Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
  }
  double norm() {
    return sqrt(sqr(x) + sqr(y) + sqr(z));
  }
  Point normalize() {
    double l = norm();
    return Point(x / l, y / l, z / l);
  }
  void output() {
    double lat = asin(z);
    double lon = atan2(y / cos(lat), x / cos(lat));
	lat /= PI / 180;
	lon /= PI / 180;
    cout << fixed << setprecision(6) << lon << " " << lat << endl;
  }
};

bool check(Point l, Point a, Point b) {
  Point x(a.x, b.x, -l.x), y(a.y, b.y, -l.y);
  Point xy = x * y;
  assert(sgn(xy.z));
  xy = xy * (1 / xy.z);
  double p = xy.x, q = xy.y;
  assert(sgn(((a * p) + (b * q) + (l * (-1))).norm()) == 0);
  return sgn(p) == 1 && sgn(q) == 1;
}

int main() {
  Point a, b, c, d;
  while (a.input() && b.input() && c.input() && d.input()) {
    Point l = ((a * b) * (c * d)).normalize();
//	cerr << l.x << ' ' << l.y << ' ' << l.z << endl;
    if (check(l, a, b) && check(l, c, d)) {
      printf("NO ");
      l.output();
    } else {
      l = l * (-1);
      if (check(l, a, b) && check(l, c, d)) {
        printf("NO ");
        l.output();
      } else {
        puts("YES");
      }
    }
  }
  return 0;
}
