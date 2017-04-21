#include <bits/stdc++.h>

using namespace std;

const int maxt = 100 + 10, maxn = 1e5 + 10;
bool vis[maxt];
bitset<maxn> bs[maxt];

struct Line {
  long long a, b, c;
  Line() {}
  Line(long long x1, long long y1, long long x2, long long y2) {
    a = y1 - y2;
    b = x2 - x1;
    c = - a * x1 - b * y1;
  }
  long long calc(long long x, long long y) {
    return a * x + b * y + c;
  }
} line[maxn];

int main() {
  int n, t;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    line[i] = Line(x1, y1, x2, y2);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int j = 0; j < n; ++j) {
      if (line[j].calc(x, y) > 0) {
        bs[i].set(j);
      }
    }
  }
  memset(vis, 0, sizeof vis);
  int ans = 0;
  for (int i = 0; i < t; ++i) {
    ans += !vis[i];
    for (int j = i + 1; j < t; ++j) {
      vis[j] |= (bs[i] ^ bs[j]).count() == 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
