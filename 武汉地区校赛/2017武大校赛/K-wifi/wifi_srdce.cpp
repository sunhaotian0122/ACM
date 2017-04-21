#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y): x(x), y(y) {}
  void input(int num) {
    cin >> x >> y;
  }
} p[maxn];
int n, father[maxn];

inline long long sqr(long long x) {
  return x * x;
}

inline long long calc_dis(Point &a, Point &b) {
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int getfather(int x) {
  if (father[x] < 0) {
    return x;
  }
  return father[x] = getfather(father[x]);
}

void merge(int x, int y) {
  x = getfather(x);
  y = getfather(y);
  if (x != y) {
    father[x] += father[y];
    father[y] = x;
  }
}

pair<bool, long long> check(long long x) {
  for (int i = 0; i < n; ++i) {
    father[i] = -1;
  }
  long long ret = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      long long dis = calc_dis(p[i], p[j]);
      if (dis <= x) {
        ret = max(ret, dis);
        merge(i, j);
      }
    }
  }
  return make_pair(father[getfather(0)] == -n, ret);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    p[i].input(i);
  }
  long long l = -1, r = 2e17 + 1;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    pair<bool, long long> ret = check(mid);
    if (ret.first) {
      r = ret.second;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(9) << sqrt(0.25 * r) << endl;
  return 0;
}
