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

const int maxn = 50 + 5;

int n, p;
int a[maxn];
ll dp[maxn][maxn][maxn];
long double f[maxn];
long double c[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	cin >> p;

	f[0] = 1;
	fer (i, 1, maxn) f[i] = f[i-1] * i;

	rep (z, n)
	{
		vector<int> v;
		rep (i, n) if (i != z) v.pb (a[i]);

		memset (dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		fer (i, 1, n) fer (k, 0, i+1) fer (s, 0, maxn)
			dp[i][k][s] = dp[i-1][k][s] + (k && s >= v[i-1] ? dp[i-1][k-1][s-v[i-1]] : 0);

		fer (k, 0, n)
		{
			ll tot = 0;
			fer (s, max (0, p-a[z]+1), p+1)
				tot += dp[n-1][k][s];
			c[k] += tot * f[k] * f[n-k-1];
		}
	}

	if (accumulate (a, a+n, 0) <= p)
		c[n] = f[n];

	long double ans = 0;
	rep (i, n+1)
	{
//		cerr << c[i] << endl;
		ans += i * c[i];
	}

	cout << fixed << setprecision (10) << ans / f[n] << endl;

	{ int _; cin >> _; return 0; }
}
