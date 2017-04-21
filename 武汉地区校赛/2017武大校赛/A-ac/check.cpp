#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;

long long x[1000];
long long cost[1000];
long long use[1000];

long long sqr(long long a)
{
	return a * a % m;
}

long long get(long long a, long long b)
{
	return min(a % b, b % a);
}

int update(int y)
{
	int ret = -1;
	long long res = cost[0];
//	cerr << "update " << y << endl;
	for (int i = 1; i <= n; i++)
	{
		if (use[i]) continue;
//		cerr << x[i] << ' ' << x[y] << ' ' << __gcd(x[i], x[y]) << endl;
		cost[i] = min(cost[i], get(x[i], x[y]));
		if (cost[i] < res)
		{
			ret = i;
			res = cost[i];
		}
	}
	return ret;
}

int main()
{
	memset(cost, 0x3f, sizeof cost);
	cin >> n >> x[1] >> a >> b >> c >> m;
	for (int i = 2; i <= n; i++)
	{
		x[i] = (sqr(x[i - 1]) * a + b * x[i - 1] + c) % m;
//		cerr << x[i] << endl;
	}
	use[1] = 1;
	int nxt = 1;
	long long ans = 0;
	while ((nxt = update(nxt)) != -1)
	{
		ans += cost[nxt];
		use[nxt] = 1;
//		cerr << nxt << ' ' << cost[nxt] << endl;
	}
	cout << ans << endl;
	return 0;
}
