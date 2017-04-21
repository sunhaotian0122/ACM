#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int maxm = 1010;
long long fac[maxm], inv[maxm], dp[55][maxm];

long long fast_pow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % MOD) {
    if (y & 1) {
      ret = ret * x % MOD;
    }
  }
  return ret;
}

void init() {
  fac[0] = 1;
  for (int i = 1; i < maxm; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  for (int i = 0; i < maxm; ++i) {
    inv[i] = fast_pow(fac[i], MOD - 2);
  }
}

long long c(int x, int y) {
  assert(x >= y);
  return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main() {
  init();
  long long sum = 0, n, k, tot = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (i == 0) {
      dp[i + 1][1] = 1;
      sum += k;
      continue;
    }
    for (int j = 1; j <= sum; ++j) {
      for (int l = 1; l <= k; ++l) {
        (dp[i + 1][j + l] += dp[i][j] * c(j - 1 + l, l) % MOD * c(sum + k - l - j, k - l) % MOD) %= MOD;
      }
      for (int l = 1; l <= sum - j + 1; ++l) {
        (dp[i + 1][j + l] += dp[i][j] * c(sum + k - j - l, k - 1) % MOD) %= MOD;
      }
    }
    sum += k;
    (tot *= c(sum, k)) %= MOD;
  }
  long long ans = 0, inv_tot = fast_pow(tot, MOD - 2);
  for (int i = 1; i <= sum; ++i) {
    (ans += dp[n][i] * inv_tot % MOD * i) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
