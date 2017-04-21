#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	random_device rd;
	int m = atoi(argv[2]);
	cout << n << ' ' << rd() % m << ' ' << rd() % m << ' ' << rd() % m << ' ' << rd() % m << ' ' << m << endl;
	return 0;
}
