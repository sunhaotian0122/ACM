#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000, maxt = 100;

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
	if (sgn < 0) return -1;
	else if (sgn > 0) return 1;
	return 0;
}
int main(int argc, char **argv)
{
	assert(argc == 3);
	int n = atoi(argv[1]), t = atoi(argv[2]);
	assert(n <= 1000000);
	assert(t <= 100);
	assert(n >= 0);
	assert(t >= 0);
	random_device rd;
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
#define line wire
		int type = rd() % 6;
		int locx1 = rd() % 999999 + 1;
		int locx2 = rd() % 999999 + 1;
		line[i].s = point(locx1, locx1);
		line[i].t = point(locx2, locx2);
		if (type == 0)
			line[i].s.x = 0, line[i].t.x = 1000000;
		else if (type == 1)
			line[i].s.x = 0, line[i].t.y = 1000000;
		else if (type == 2)
			line[i].s.y = 0, line[i].t.x = 1000000;
		else if (type == 3)
			line[i].s.y = 0, line[i].t.y = 1000000;
		else if (type == 4)
			line[i].s.x = 1000000, line[i].t.y = 1000000;
		else if (type == 5)
			line[i].s.x = 0, line[i].t.y = 0;
#undef line
	}
	for (int i = 0; i < t;)
	{
		int xx = rd() % 999800 + 1;
		int yy = rd() % 999800 + 1;
		for (int jj = 0; jj < 10 && i < t; i++, jj++)
		{
			team[i].x = rd() % 100 + xx;
			team[i].y = rd() % 100 + yy;
			while (1)
			{
				bool check = true;
				for (int j = 0; j < n && check; j++)
					if (side(wire[j], team[i]) == 0)
						check = false;
				for (int j = 0; j < i && check; j++) if (team[i] == team[j]) check = false;
				if (check) break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << wire[i].s.x << ' ' << wire[i].s.y << ' '
			 << wire[i].t.x << ' ' << wire[i].t.y << endl;
	cout << t << endl;
	for (int i = 0; i < t; i++)
		cout << team[i].x << ' ' << team[i].y << endl;
	return 0;
}
