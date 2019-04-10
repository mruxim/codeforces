// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, nb;
ll k;
int a[maxn], b[maxn];
int fl[maxn], fr[maxn];

void add (int *f, int p, int x) { for (p++; p <= nb; p += p & -p) f[p] += x; }
int get (int *f, int p) { int r = 0; for (p++; p; p -= p & -p) r += f[p]; return r; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> a[i];

	copy (a, a+n, b);
	sort (b, b + n);
	nb = unique (b, b + n) - b;

	rep (i, n) a[i] = lower_bound (b, b + nb, a[i]) - b;

	ll ans = 0;

	ll cur = 0;
	int r;

	for (r = n; --r; )
		cur += get (fr, a[r]-1),
		add (fr, a[r], 1);
	r++;

	rep (l, n)
	{
		if (l == r) { cur -= get (fr, a[r]-1) + l - get (fl, a[r]); add (fr, a[r], -1); r++; }

		cur += l - get (fl, a[l]) + get (fr, a[l]-1);
		add (fl, a[l], 1);

		while (r < n && cur > k) { cur -= get (fr, a[r]-1) + (l+1) - get (fl, a[r]); add (fr, a[r], -1); r++; }
		ans += n - r;
	}

	cout << ans << endl;

	{ int _; cin >> _; }
	return 0;
}
