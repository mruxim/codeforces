#include <iostream>

using namespace std;

const int MAXn = 100000 + 100;

int n;
int a[MAXn], _c[2*MAXn + 100], *c = _c + MAXn + 50;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = a[i] - min (i, n - i - 1);
		c[a[i]]++;
	}
	int res = n;
	for (int i = -MAXn; i < MAXn; i++)
		res = min (res, n - c[i]);
	cout << res << endl;
	{ int _; cin >> _; }
}
