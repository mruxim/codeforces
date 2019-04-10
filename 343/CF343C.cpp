// .... .... .....!
// P..... C.....!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
ll h[maxn], p[maxn];

inline ll Abs (ll x) { return max (x, -x); }

bool check (ll x)
{
	int k = 0;
	rep (i, n)
	{
		ll mn = p[k], mx = p[k];
		while (k < m && (Abs (h[i] - mn) + Abs (mn - mx) <= x || Abs (h[i] - mx) + Abs (mn - mx) <= x))
			k++, mn = min (mn, p[k]), mx = max (mx, p[k]);
		if (k == m) return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> h[i];
	rep (i, m) cin >> p[i];

	ll lo = -1, hi = 1e11;
	while (hi - lo > 1)
	{
		ll md = (lo + hi) / 2;
		if (check (md))
			hi = md;
		else
			lo = md;
	}

	cout << hi << endl;

	{ int _; cin >> _; return 0; }
}
