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
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <ll, ll> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
pii p[maxn];
ll mny[maxn], mxy[maxn];

bool check (ll dis)
{
	mny[n] = 1ll << 35, mxy[n] = -(1ll << 35);
	rof (i, n, 0) mny[i] = min (mny[i+1], p[i].Y), mxy[i] = max (mxy[i+1], p[i].Y);

	int pos = 0;
	ll h = 1LL << 35;
	ll mn = 1ll << 35, mx = -(1ll << 35);

	rep (i, n)
	{
		if (i) mn = min (mn, p[i-1].Y), mx = max (mx, p[i-1].Y);
		if (mx - mn > dis) break;
		while (pos < n && p[pos].X <= p[i].X + dis) pos++;
		h = min (h, max (mx, mxy[pos]) - min (mn, mny[pos]));
	}
	return h <= dis;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> p[i].X >> p[i].Y, p[i].X += p[i].Y, p[i].Y = p[i].X - 2*p[i].Y;

	sort (p, p+n);

	ll lo = -1, hi = (ll)(1e10+0.5);
	while (hi - lo > 1)
	{
		ll md = (hi + lo + 1) / 2;
		if (check (md)) hi = md;
		else lo = md;
	}
	
	cout << fixed << hi / 2.0 << endl;

	{ int _; cin >> _; return 0; }
}
