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

const int maxn = 100 + 10;

int n;
pii p[maxn];

inline int sqr (int v) { return v*v; }

bool can (pii a, pii b, pii c)
{
	int dis[3] = {sqr(a.X-b.X) + sqr (a.Y-b.Y),
		sqr(a.X-c.X) + sqr (a.Y-c.Y),
		sqr(b.X-c.X) + sqr (b.Y-c.Y)};
	
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> p[i].X >> p[i].Y;

	sort (p, p+n);

	

	rep (i, n) rep (j, i) rep (k, j) if (can (p[i], p[j], p[k]))

	{ int _; cin >> _; return 0; }
}
