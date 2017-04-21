#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
const double eps = 0.1;
const double eps2 = 1e-6;
random_device rd;
struct point3d{
	double x, y, z;
	double lat, lon, r;
	void read(double _r)
	{
		r = _r;
		if (scanf("%lf%lf", &lat, &lon) == -1) exit(0);
		lat = (90 - lat) * pi / 180;
		lon += 180;(lon *= pi) /= 180;
		x = r * sin(lat) * cos(lon);
		y = r * sin(lat) * sin(lon);
		z = r * cos(lat);
	}
	void gen(double _r, char *buf)
	{
		r = _r;
		lat = (int(rd() % 180000u - 90000)) / 1000.;
		lon = (int(rd() % 360000u - 180000)) / 1000.;
		sprintf(buf, "%.3lf %.3lf", lat, lon);
		lat = (90 - lat) * pi / 180;
		lon *= pi / 180;
		x = r * sin(lat) * cos(lon);
		y = r * sin(lat) * sin(lon);
		z = r * cos(lat);
	}

	const point3d operator * (const point3d &b) const
	{
		point3d ret;
		ret.x = y * b.z - z * b.y;
		ret.y = z * b.x - x * b.z;
		ret.z = x * b.y - y * b.x;
		return ret;
	}
	void normalize()
	{
		double len = sqrt(x * x + y * y + z * z);
		x /= len;y /= len;z /= len;
	}
	void make()
	{
		r = sqrt(x * x + y * y + z * z);
		lat = acos(z / r);
		lon = atan2(y, x);
		lat *= 180 / pi;
		lon *= 180 / pi;
		lat = 90 - lat;
	}
};

struct line3d{
	point3d a, b;
};

int sgn(double x)
{
	if (x > eps2) return 1;
	else if (x < -eps2) return -1;
	return 0;
}

bool check2(point3d a, point3d b)
{
	return sgn(a.x) == sgn(b.x) &&
		   sgn(a.y) == sgn(b.y) &&
		   sgn(a.z) == sgn(b.z);
}

bool checkres(point3d a, point3d b, point3d c, point3d d, point3d res)
{
	point3d p1 = a * res, p2 = res * b;
	point3d p3 = c * res, p4 = res * d;
	point3d pa = a * b, pc = c * d;
	return check2(p1, pa) && check2(p2, pa) &&
		   check2(p3, pc) && check2(p4, pc);
}

double norm(point3d p)
{
	return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

bool checkres2(point3d a, point3d b, point3d c, point3d d, point3d res)
{
	point3d p1 = res * a, p2 = b * res;
	point3d p3 = res * c, p4 = d * res;
	return norm(p1) > eps && norm(p2) > eps &&
		   norm(p3) > eps && norm(p4) > eps &&
		   norm(a * b) > eps && norm(c * d) > eps &&
		   norm(a * c) > eps && norm(b * d) > eps &&
		   norm(a * d) > eps && norm(b * c) > eps;
}

bool sol(int &yes, int &no)
{
	char input[4][1024];
	point3d a, b, c, d;
	a.gen(1., input[0]);b.gen(1., input[1]);
	c.gen(1., input[2]);d.gen(1., input[3]);
	point3d ra = (a * b) * (c * d);
	point3d rb;
	rb.x = -ra.x;rb.y = -ra.y;rb.z = -ra.z;
	if (norm(ra) < eps) return false;
	ra.normalize();ra.make();
	rb.normalize();rb.make();
//	cout << ra.x << ' ' << ra.y << ' ' << ra.z << endl;
	if (!(checkres2(a, b, c, d, ra) && checkres2(a, b, c, d, rb))) return false;

	if (checkres(a, b, c, d, ra)) {
		if (!no) return false;
		no--;
		printf("NO %.8lf %.8lf\n", ra.lon, ra.lat);
	} else if (checkres(a, b, c, d, rb)) {
		if (!no) return false;
		no--;
		printf("NO %.8lf %.8lf\n", rb.lon, rb.lat);
	} else {
		if (!yes) return false;
		yes--;
		printf("YES\n");
	}
	fprintf(stderr, "%s %s %s %s\n", input[0], input[1], input[2], input[3]);
	return true;
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int max_yes = n * 2 / 3;
	int max_no = n * 2 / 3;
	while (n) n -= sol(max_yes, max_no);
	return 0;
}
