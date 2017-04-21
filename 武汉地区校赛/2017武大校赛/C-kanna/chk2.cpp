#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int maxe = 2000 * 10;
const int inf = 0x3fffffff;
struct edge{
	int v, c, n;
	edge(){}
	edge(int _v, int _c, int _n):
		v(_v), c(_c), n(_n){}
}edg[maxe];

struct point{
	int x, y, r, w;
}p[maxn];

vector<int> inte[maxn];

int h[maxn], c[maxn], te;
void addedge(int u, int v, int c)
{
	edg[te] = edge(v, c, h[u]);h[u] = te++;
	edg[te] = edge(u, 0, h[v]);h[v] = te++;
}

int S, T, N;

long long sqr(long long a){return a * a;}

bool check(int a, int b)
{
	int x1 = p[a].x, y1 = p[a].y, r1 = p[a].r;
	int x2 = p[b].x, y2 = p[b].y, r2 = p[b].r;
	return sqr(x1 - x2) + sqr(y1 - y2) < sqr(r1 + r2);
}

int lay[maxn], que[maxn], qh, qt;

bool bfs()
{
	memset(lay, -1, sizeof(int) * (N + 5));
	lay[S] = 0;
	que[qh = qt = 0] = S;
	while (qh <= qt)
	{
		int u = que[qh++];
		for (int e = h[u]; ~e; e = edg[e].n)
		{
			int v = edg[e].v;
			if (edg[e].c && lay[v] == -1)
			{
				lay[v] = lay[u] + 1;
				que[++qt] = v;
			}
		}
	}
	return lay[T] != -1;
}

long long dfs(int u, int mx)
{
	if (u == T) return mx;
	long long ans = 0;
	for (int c = h[u]; (~c) && mx; c = edg[c].n)
	{
		long long tans;
		if (lay[edg[c].v] == lay[u] + 1 && (tans = dfs(edg[c].v, min(mx, edg[c].c))))
		{
			edg[c].c -= tans;
			edg[c ^ 1].c += tans;
			ans += tans;
			mx -= tans;
		}
	}
	return ans;
}

long long dinic()
{
	long long ans = 0;
	while (bfs())
	{
		long long tans = 0;
		while ((tans = dfs(S, 0x3fffffff)))
			ans += tans;
	}
	return ans;
}

void color(int u)
{
	int tc = c[u];
	for (int v : inte[u])
	{
		if (c[v] == -1)
		{
			c[v] = (tc ^ 1);
			color(v);
		} else {
			assert(c[v] != tc);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("1.in", "r", stdin);
	long long sum = 0;
	memset(h, -1, sizeof h);
	cin >> N;
	S = 0;T = N + 1;
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i].x >> p[i].y >> p[i].r >> p[i].w;
		sum += p[i].w;
	}
	memset(c, -1, sizeof c);
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++)
		{
//			cerr << "Check " << i << ' ' << j << endl;
			if (check(i, j))
			{
				inte[i].push_back(j),
				inte[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (c[i] == -1)
		{
			c[i] = 0;
			color(i);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (c[i] == 0)
		{
			addedge(S, i, p[i].w);
			for (int v : inte[i])
				addedge(i, v, inf);
		} else 
		{
			addedge(i, T, p[i].w);
		}
	}
	cout << sum - dinic() << endl;
	return 0;
}
