#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1 << 28;

int n, r = INF;

int cnt (int a, int b)
{
	if (a == 0)
		return (b == 1) ? 0 : INF;
	return (b / a) + cnt (b % a, a);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		r = min (r, cnt (i, n) - 1);
	cout << r << endl;
	{ int _; cin >> _; }
}
