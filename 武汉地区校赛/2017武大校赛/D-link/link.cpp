#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
const double eps = 1e-6;

struct point3d{
	double x, y, z;
	double lat, lon, r;
	bool read(double _r)
	{
		r = _r;
		if (scanf("%lf%lf", &lat, &lon) == -1) return false;
		lat = (90 - lat) * pi / 180;
		lon *= pi / 180;
		x = r * sin(lat) * cos(lon);
		y = r * sin(lat) * sin(lon);
		z = r * cos(lat);
		cerr << x << ' ' << y << ' ' << z << endl;
		return true;
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

int sgn(double x)
{
	if (x > eps) return 1;
	else if (x < -eps) return -1;
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

bool sol()
{
	point3d a, b, c, d;
	if (!(a.read(1.) && b.read(1.) && c.read(1.) && d.read(1.))) return false;
	point3d ra = (a * b) * (c * d);
	point3d rb;
	rb.x = -ra.x;rb.y = -ra.y;rb.z = -ra.z;
	ra.normalize();ra.make();
	rb.normalize();rb.make();

	if (checkres(a, b, c, d, ra)) printf("NO %.8lf %.8lf\n", ra.lon, ra.lat);
	else if (checkres(a, b, c, d, rb)) printf("NO %.8lf %.8lf\n", rb.lon, rb.lat);
	else printf("YES\n");
	return true;
}

int main()
{
	while (sol());
	return 0;
}
