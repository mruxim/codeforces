#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, k, c;
bool a[500];

int main()
{
	cin >> n >> k >> c;
	for (int i = 0; i < c; i++)
	{
		int t;
		cin >> t;
		a[t] = 1;
	}
	int p = 0, r = 0;
	for (int i = 1; i <= n; i++)
		if (p == i - k || a[i])
			r++, p = i;
	cout << r << endl;
	{ int _; cin >> _; }
}
