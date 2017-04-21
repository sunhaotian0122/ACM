#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;

typedef pair<long long, long long> pll;
pll pos[maxn];
long long dist[maxn];

bool select[maxn];

#define x first
#define y second

int n;

long long sqr(const long long x) {return x * x;}

long long get_dist(const pll &a, const pll &b)
{
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int update(int id)
{
	int ret = -1;
	long long current = (1ll << 62);
	for (int i = 0; i < n; i++)
	{
		if (select[i]) continue;
		dist[i] = min(dist[i], get_dist(pos[id], pos[i]));
		if (dist[i] < current)
		{
			current = dist[i];
			ret = i;
		}
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i].x >> pos[i].y;
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	long long ans = 0;
	int last = 0;
	select[0] = 1;
	for (int i = 1; i < n; i++)
	{
		last = update(last);
		ans = max(ans, dist[last]);
		select[last] = 1;
	}
	cout << fixed << setprecision(12) << sqrt(ans) / 2 << endl;
	return 0;
}
