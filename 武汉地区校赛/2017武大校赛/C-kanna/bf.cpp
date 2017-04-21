#include <bits/stdc++.h>
using namespace std;
const int N = 2010, inf = 1e9;
struct circle
{
	int x, y, r, w;
}a[N];
int f[N][N], h[N], dis[N];
int n;
void update(int &x, int y)
{
	x = (x >= y ? x : y);
}
bool check(int i, int j, int k)
{
	if(a[k].y - a[k].r < dis[i])
		return 0;
	long long dist, dx, dy;
	dx = (a[j].x - a[k].x);
	dy = (a[j].y - a[k].y);
	dist = a[j].r + a[k].r;
	if(dx * dx + dy * dy < dist * dist)
		return 0;
	return 1;
}
int main()
{
	//freopen("5.in", "r", stdin);
	//freopen("5.bfout", "w", stdout);	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].r, &a[i].w);
		dis[i] = a[i].y - a[i].r;
	}
	sort(dis + 1, dis + 1 + n);
	dis[0] = -inf * 2;
	int len = unique(dis + 1, dis + 1 + n) - dis - 1;
	dis[len + 1] = inf * 2;
	for(int i = 1; i <= len; ++i)
	{
		//printf("$%d\n", i);
		int nextc = inf * 2;
		for(int j = 1; j <= n; ++j)
			if(a[j].y - a[j].r >= dis[i])
			{
				update(f[i][j], h[i] + a[j].w);
				if(a[j].y + a[j].r <= dis[i + 1])
					update(h[i + 1], f[i][j]);
				nextc = min(nextc, a[j].y - a[j].r);
			}
		nextc = dis[lower_bound(dis + 1, dis + 1 + len, nextc) - dis];
		for(int j = 1; j <= n; ++j)
			if(a[j].y - a[j].r <= nextc/* && a[j].y + a[j].r > nextc*/)
			{
				for(int k = 1; k <= n; ++k)
					if(check(i, j, k))
					{
						int low = min(a[j].y + a[j].r, a[k].y + a[k].r);
						if(low == a[j].y + a[j].r)
						{
							int mp = lower_bound(dis + 1, dis + 1 + n, low) - dis;
							update(f[mp][k], f[i][j] + a[k].w);
							if(a[k].y + a[k].r <= dis[i + 1])
								update(h[i + 1], f[mp][k]);
						}
						else
						{
							int mp = lower_bound(dis + 1, dis + 1 + n, low) - dis;
							update(f[mp][j], f[i][j] + a[k].w);
							if(a[j].y + a[j].r <= dis[i + 1])
								update(h[i + 1], f[mp][j]);
						}	
					}
			}
		for(int j = 1; j <= n; ++j)
		{
			update(f[i + 1][j], f[i][j]);
			if(a[j].y + a[j].r <= dis[i + 1])
				update(h[i + 1], f[i + 1][j]);
		}
		update(h[i + 1], h[i]);
	}
	printf("%d\n", h[len + 1]);
	return 0;
}
