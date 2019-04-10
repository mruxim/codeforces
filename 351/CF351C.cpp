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

int n, m;
int a[22], b[22];
int best[55][25];
int dp[55][55];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i];
	rep (i, n) cin >> b[i];

	memset (best, 50, sizeof best);

	rep (mask, 0, 1<<n)
	{
		int mn = 0, tot = 0;
		int ink = 0;
		rep (i, n)
			if (mask >> i & 1)
				ink += a[i], tot++;
			else
				ink += b[i], tot--, mn = min (mn, tot);
		best[tot+25][mn] = min (best[tot+25][mn], ink);
	}

	

	{ int _; cin >> _; return 0; }
}
