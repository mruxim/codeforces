// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

////////////////////////////////////////////////////////////////////////////////

const ll inf = 1LL << 62;

const int maxn = 2*1000000 + 1000;

int n;
ll S;
pll b[maxn];
pii s[maxn];
pll dp[maxn];

inline bool better (pll p1, pll p2)
{
	if (p1.X != p2.X) return p1.X < p2.X;
	return p1.Y > p2.Y;
}

pll cost (int i, int prev)
{
	ll need = b[i].X - dp[prev].Y;
	if (need <= 0) return pll (dp[prev].X, dp[prev].Y - b[i].X);
	ll remt = (need + b[prev].Y - 1) / b[prev].Y;
	ll after = dp[prev].Y + remt * b[prev].Y - b[i].X;
	return pll (dp[prev].X + remt, after);
}

int bs (int i, int prev)
{
	int lo = i, hi = n+1;
	while (hi - lo > 1)
	{
		int md = (lo + hi) / 2;
		if (better (cost (md, i), cost (md, prev)))
			hi = md;
		else
			lo = md;
	}
	return hi;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> S;
	rep (i, n) cin >> b[i].Y >> b[i].X;
	sort (b, b+n);
	n = unique (b, b+n) - b;
	int nn = 0;
	rep (i, n)
		if (nn > 0 && b[i].X == b[nn-1].X)
			b[nn-1] = b[i];
		else if (nn == 0 || b[i].Y > b[nn-1].Y)
			b[nn++] = b[i];
	n = nn;
	rof (i, n, 0) b[i+1] = b[i];

	dp[0] = pll (0, 0);

	int head = 0, tail = 0;
	s[tail++] = pii (0, 1);

	ll ans = inf;
	b[0] = mkp (0, 0);
	while (b[n].X >= S) n--;
	b[++n] = pll (S, 1);

	fer (i, 1, n+1)
	{
		if (i == 1)
		{
			dp[i] = cost (1, 0);
			ll need = S - dp[i].Y;
			ll remt = 0;
			if (need > 0) remt = (need + b[i].Y - 1) / b[i].Y;
			smin (ans, max (remt, 0LL) + dp[i].X);
			s[tail++] = pii (1, 2);
			head++;
			continue;
		}
		while (head+1 < tail && s[head+1].Y <= i)
			head++;

		dp[i] = cost (i, s[head].X);
		
		ll need = S - dp[i].Y;
		ll remt = 0;
		if (need > 0) remt = (need + b[i].Y - 1) / b[i].Y;
		smin (ans, max (remt, 0LL) + dp[i].X);

		while (tail-head >= 2 && better (cost (s[tail-1].Y, i), cost (s[tail-1].Y, s[tail-1].X))) tail--, cerr << "VVV" << endl;
		int when = bs (i, s[tail-1].X);
		if (when != n+1) s[tail++] = pii (i, when);
	}

	cout << dp[n].X << endl;

	{ int _; cin >> _; return 0; }
}
