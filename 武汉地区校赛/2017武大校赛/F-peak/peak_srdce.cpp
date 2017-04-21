#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
int father[maxn][24], depth[maxn];
vector<int> vec[maxn];

void dfs(int cur, int fa) {
  depth[cur] = depth[fa] + 1;
  father[cur][0] = fa;
  for (int i = 0; i < 23; ++i) {
    father[cur][i + 1] = father[father[cur][i]][i];
  }
  for (int i = 0, sz = vec[cur].size(); i < sz; ++i) {
    if (vec[cur][i] != fa) {
      dfs(vec[cur][i], cur);
    }
  }
}

int get_lca(int x, int y) {
  if (depth[x] < depth[y]) {
    swap(x, y);
  }
  int delta = depth[x] - depth[y];
  for (int i = 0; i <= 23; ++i) {
    if ((delta >> i) & 1) {
      x = father[x][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = 23; ~i; --i) {
    if (father[x][i] != father[y][i]) {
      x = father[x][i];
      y = father[y][i];
    }
  }
  return father[x][0];
}

long long sum[maxn];

void dp(int cur, int fa) {
  for (int i = 0, sz = vec[cur].size(); i < sz; ++i) {
    int nxt = vec[cur][i];
    if (nxt != fa) {
      dp(nxt, cur);
      sum[cur] += sum[nxt];
    }
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  dfs(1, 0);
  while (k--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    int lca = get_lca(x, y);
    sum[x] += w;
    sum[y] += w;
    sum[lca] -= w;
    sum[father[lca][0]] -= w;
  }
  dp(1, 0);
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    if (sum[i] > sum[ans]) {
      ans = i;
    }
  }
  cout << ans << " " << sum[ans] << endl;
  return 0;
}
