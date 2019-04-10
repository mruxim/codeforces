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

ll n, t;
ll c[66][66];

int cnt (ll x)
{
	int ret = 0;
	while (x) ret += x&1, x /= 2;
	return ret;
}

int lg (ll x)
{
	int ret = 0;
	while (x > 1) ret++, x /= 2;
	return ret;
}

int main()
{
	ios::sync_with_stdio (false);

	rep (i, 66)
	{
		c[i][0] = c[i][i] = 1;
		fer (j, 1, i) c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	cin >> n >> t;

	if (t & (t-1)) cout << 0 << endl;
	else
	{
		int k = 0;
		while (t) k++, t >>= 1;

		n += 2;
		ll ans = 0;
		while (n)
		{
			ll lb = n&-n;
			n -= lb;
			if (k - cnt (n) < 0 || lg (lb) - k + cnt (n) < 0) continue;
			ans += c[lg(lb)][k-cnt(n)];
		}
		cout << ans - (k==1) << endl;
	}

	{ int _; cin >> _; return 0; }
}
