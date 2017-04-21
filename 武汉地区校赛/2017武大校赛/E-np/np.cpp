#include <bits/stdc++.h>

using namespace std;

double a[10005][3];
double ans[10005][9];
int n;

double calc(int _i, int _a, int _b, int _c)
{
	double _res[3];
	memset(_res, 0, sizeof _res);
	_res[0] = _res[1] = _res[2] = 1;
	_res[_a] += a[_i - 2][_a];
	_res[_b] += a[_i - 1][_b];
	_res[_c] += a[_i][_c];
//	printf("%d %d %d %d = %.6lf (%.3lf * %.3lf * %.3lf)\n", _i, _a, _b, _c, _res[_a] * _res[_b] * _res[_c], _res[_1]);
	return _res[0] * _res[1] * _res[2];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	for (int i = 0; i < 3; i++)
		ans[1][i] = 1 + a[1][i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j)
			{
				ans[2][i * 3 + j] = ans[1][i] + (1 + a[1][i]) * (1 + a[2][j]);
			} else {
				ans[2][i * 3 + j] = ans[1][i] + (1 + a[1][i] + a[2][j]);
			}
	for (int i = 3; i <= n; i++)
	{
		for (int _a = 0; _a < 3; _a++)
		{
			for (int _b = 0; _b < 3; _b++)
			{
				for (int _c = 0; _c < 3; _c++)
				{
					ans[i][_b * 3 + _c] = max(
							ans[i][_b * 3 + _c],
							ans[i - 1][_a * 3 + _b] + calc(i, _a, _b, _c));
				}
			}
		}
	}
	double _ans = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_ans = max(_ans, ans[n][i * 3 + j]);
	printf("%.8f\n", _ans);
	return 0;
}
