#include <bits/stdc++.h>

using namespace std;

const int maxm = 3e6 + 5;

vector<pair<int, int>> vec[maxm];
int cnt[maxm], father[maxm], last[maxm], vis[maxm], rnk[maxm];
long long m;
stack<int> sta;

int getfather(int x) {
  if (father[x] == -1) {
    return x;
  }
  return father[x] = getfather(father[x]);
}

void merge(int x, int y) {
  x = getfather(x);
  y = getfather(y);
  if (rnk[x] > rnk[y]) {
    father[y] = x;
  } else if (rnk[x] < rnk[y]) {
    father[x] = y;
  } else {
    rnk[x]++;
    father[y] = x;
  }
}

int main() {
  long long n, x, a, b, c;
  cin >> n >> x >> a >> b >> c >> m;
  long long st = clock();
  for (int i = 0; i < n; ++i) {
    ++vis[x];
    x = (a * x % m * x + b * x + c) % m;
  }
  last[m] = m;
  for (int i = m - 1; i; --i) {
    last[i] = last[i + 1];
    if (vis[i + 1] > 0) {
      last[i] = i + 1;
    }
  }
  for (int i = 1; i < m; ++i) {
    if (vis[i]) {
      if (last[i + 1] != m && last[i + 1] < i + i) {
        vec[last[i + 1] % i].push_back(make_pair(i, last[i + 1]));
      }
      for (int j = i + i; j < m; j += i) {
        if (vis[j]) {
          vec[0].push_back(make_pair(i, j));
        } else if (last[j] != m && last[j] < i + j) {
          vec[last[j] - j].push_back(make_pair(i, last[j]));
        }
      }
    }
  }
  memset(father, -1, sizeof father);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    for (auto &edge: vec[i]) {
      int fx = getfather(edge.first), fy = getfather(edge.second);
      if (getfather(edge.first) != getfather(edge.second)) {
        merge(edge.first, edge.second);
        ans += i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
