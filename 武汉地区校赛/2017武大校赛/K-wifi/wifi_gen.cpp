#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int limit = 100000001;
	if (argc == 3) limit = atoi(argv[2]);
	random_device rd;
	cout << n << endl;
	for (int i = 1; i <= n; i++)
		cout << rd() % limit << ' ' << rd() % limit << endl;
	return 0;
}
