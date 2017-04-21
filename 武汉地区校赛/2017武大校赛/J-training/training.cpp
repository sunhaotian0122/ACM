#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 52, maxk = 1005;
long long dp[maxn][maxk];
long long prod[maxk], prod_inv[maxk];
int n;

long long pow_mod(long long a, long long p)
{
	long long ret = 1;
	while (p)
	{
		if (p & 1)
			(ret *= a) %= mod;
		(a *= a) %= mod;
		p >>= 1;
	}
	return ret;
}

long long c(long long a, long long b)
{
//	cerr << "C(" << a << ',' << b << ")\n";
	if (a < b) return 0;
	if (a < 0 || b < 0) return 0;
	return prod[a] * prod_inv[b] % mod * prod_inv[a - b] % mod;
}

int main()
{
	prod[0] = 1;
	for (int i = 1; i < maxk; i++) {
		prod[i] = prod[i - 1] * i % mod;
	}
	for (int i = 0; i < maxk; i++) {
		prod_inv[i] = pow_mod(prod[i], mod - 2);
	}
	int n, tsum = 0;
	long long totsum = 1;
	dp[0][0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		(totsum *= prod_inv[k]) %= mod;
		long long _tsum = 0;
		for (int j = 0; j <= tsum; j++)
		{
			(_tsum += dp[i - 1][j]) %= mod;
			dp[i][j + 1] += _tsum * c(tsum + k - (j + 1), k - 1) % mod;
			dp[i][j + 1] %= mod;
		}
		for (int kk = 1; kk <= k; kk++)
		{
			for (int j = 1; j <= tsum; j++)
			{
				long long tk = dp[i - 1][j] * c(j - 1 + kk, kk) % mod * c(tsum - j + k - kk, k - kk) % mod;
				(dp[i][j + kk] += tk) %= mod;
			}
		}
		tsum += k;
//		for (int j = 0; j <= tsum; j++) cerr << dp[i][j] << ' ';
//		cerr << endl;
	}
	(totsum *= prod[tsum]) %= mod;
	totsum = pow_mod(totsum, mod - 2);
	long long ans = 0;
	for (int i = 1; i <= tsum; i++)
	{
//		cerr << dp[n][i] << ' ' << i << endl;
		ans += dp[n][i] * i % mod;
	}
	ans %= mod;
	(ans *= totsum) %= mod;
	cout << ans << endl;
	return 0;
}

