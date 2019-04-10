#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 100 * 1000 + 2;

int mx, my, w;

int rev (int x)
{
	int r = 0;
	while (x)
		r = r * 10 + x % 10, x /= 10;
	return r;
}

struct frac {
	int v;
	int n, d;
	bool operator < (const frac &z) const
	{
		return /*n * z.d == d * z.n ? v < z.v : */n * z.d < d * z.n;
	}
};

bool cmp (const frac &g, const frac &h)
{
		return g.n * h.d == g.d * h.n ? g.v < h.v : g.n * h.d < g.d * h.n;
}

frac a[MAX], b[MAX];
int p[MAX], q[MAX];

int main()
{
	cin >> mx >> my >> w;
	for (int i = 0; i < MAX; i++)
	{
		a[i].v = i+1;
		a[i].d = rev (a[i].v);
		int g = __gcd (a[i].v, a[i].d);
		a[i].n = a[i].v / g, a[i].d /= g;
		b[i] = a[i];
		swap (b[i].n, b[i].d);
	}

	sort (b, b + my, cmp);
	for (int i = 0; i < mx; i++)
		p[i] = lower_bound (b, b + my, a[i]) - b,
		q[i] = upper_bound (b, b + my, a[i]) - b;
	int low = 0, high = my;
	while (high - low > 1)
	{
		int mid = (low + high) / 2;
	}
	{ int _; cin >> _; }
}

