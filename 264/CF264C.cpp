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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, q;
int v[maxn], c[maxn];

ll m1, m2;
int c1, c2;
ll cf[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> q;
	rep (i, n) cin >> v[i];
	rep (i, n) cin >> c[i];

	while (q-- > 0)
	{
		fill (cf, cf+n+1, -(1LL<<61));

		ll a, b;
		cin >> a >> b;

		ll m1 = 0, m2 = -(1LL<<62);
		int c1 = 0, c2 = -1;

		ll ans = 0;
		rep (i, n)
		{
			ll val = (c[i] == c1 ? m2 : m1);

			val = max (val + v[i] * b, cf[c[i]] + v[i] * a);

			cf[c[i]] = max (val, cf[c[i]]);

			if (val <= m2 || (val <= m1 && c[i] == c1)) continue;
			if (val <= m1) m2 = val, c2 = c[i];
			else
			{
				if (c1 != c[i]) m2 = m1, c2 = c1;
				m1 = val, c1 = c[i];
			}

			ans = max (ans, val);
		}
		cout << ans << endl;
	}

	{ int _; cin >> _; return 0; }
}
