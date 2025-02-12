#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 100 * 1000 + 2;

int mx, my, w;
int a[MAX], b[MAX];
map <pair <int, int>, int> x, y;
long long rx = MAX, ry = MAX;

int rev (int x)
{
	int r = 0;
	while (x)
		r = r * 10 + x % 10, x /= 10;
	return r;
}

int main()
{
	cin >> mx >> my >> w;

	for (int i = 1; i < MAX; i++)
	{
		b[i] = rev (i);
		int g = __gcd (i, b[i]);
		a[i] = i / g, b[i] /= g;
	}

	for (int i = 1; i <= my; i++)
		y[make_pair (b[i], a[i])]++;

	long long p = my, c = 0;
	for (int i = 1; i <= mx; i++)
	{
		x[make_pair (a[i], b[i])]++;
		c += y[make_pair (a[i], b[i])];
		while (p > 1 && c - x[make_pair (b[p], a[p])] >= w)
			c -= x[make_pair (b[p], a[p])], y[make_pair (b[p], a[p])]--, p--;
		if (c >= w && i * p < rx * ry)
			rx = i, ry = p;
	}

	if (c >= w)
		cout << rx << ' ' << ry << endl;
	else
		cout << -1 << endl;
	{ int _; cin >> _; }
}
