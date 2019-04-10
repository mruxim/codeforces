#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 50 + 5;

int n;
int a[MAXn], t;
unsigned long long r[MAXn];

bool ip (int x)
{
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int next ()
{
	static int np = 2;
	while (!ip (np))
		np++;
	return np++;
}

int main()
{
	cin >> n;
	if (n == 2)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		r[i] = 1;
	for (int i = 0; i < n; i++)
		r[i] *= next();
	int np = next();
	while (18446744073709551615ULL / np >= r[n/2])
	{
		for (int i = 0; i <= n/2; i++)
			r[i] *= np;
		sort (r, r + n);
		np = next ();
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << endl;
	{ int _; cin >> _; }
}
