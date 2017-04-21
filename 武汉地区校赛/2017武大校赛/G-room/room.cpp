#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000, maxt = 100;

#define hash hs

bitset<maxn> bs[maxt];
string hash[maxt];

typedef pair<long long, long long> point;
typedef pair<point, point> line;
#define x first
#define y second
#define s first
#define t second

line wire[maxn];
point team[maxt];

int wire_count, team_count;

const point operator - (const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}

long long cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

int side(const line &li, const point &pt)
{
	auto sgn = cross(pt - li.s, li.t - li.s);
	assert(sgn != 0);
	if (sgn < 0) return -1;
	else if (sgn > 0) return 1;
	return 0;
}

int main()
{
	cin >> wire_count;
	for (int i = 0; i < wire_count; i++)
	{
		cin >> wire[i].s.x >> wire[i].s.y
			>> wire[i].t.s >> wire[i].t.y;
	}
	cin >> team_count;
	for (int i = 0; i < team_count; i++)
		cin >> team[i].x >> team[i].y;
	for (int i = 0; i < team_count; i++)
	{
		for (int j = 0; j < wire_count; j++)
		{
			int sgn = side(wire[j], team[i]);
			bs[i][j] = sgn < 0;
		}
		hash[i] = bs[i].to_string();
	}
	sort(&hash[0], &hash[team_count]);
	int ans = (team_count != 0);
	for (int i = 1; i < team_count; i++)
		if (hash[i] != hash[i - 1]) ans++;
	cout << ans << endl;
	return 0;
}
