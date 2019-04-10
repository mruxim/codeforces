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

pair<ll,int> dp[20][10][10+2];

int md (ll n)
{
	int r = 0;
	while (n) r = max (r, (int)(n%10)), n /= 10;
	return r;
}

ll brute (ll n)
{
	int r = 0;
	while (n) n -= md (n), r++;
	return r;
}

int main()
{
	ios_base::sync_with_stdio (false);

	fer (len, 1, 20) rep (mx, 10) fer (k, 1, 11)
	{
		ll cnt = 0;
		int nk = k;

		if (len == 1)
		{
			nk = 10 - nk;
			if (nk == 0 && mx == 0)
			{
				dp[len][mx][k] = mkp (0, 0);
				continue;
			}
			nk -= max (nk, mx);
			nk = -nk;
			if (nk == 0 && mx)
				dp[len][mx][k] = mkp (2, mx);
			else
				dp[len][mx][k] = mkp (1, nk);
			continue;
		}

		rof (i, 10, 0)
			cnt += dp[len-1][max(mx, i)][nk].X,
			nk = dp[len-1][max(mx, i)][nk].Y;
		dp[len][mx][k] = mkp (cnt, nk);
	}

	ll n;
	cin >> n;

	ll ans = 0;

	ll p10 = 10;
	fer (len, 1, 18)
	{
		if (!n) break;
		int mx = md (n/p10/10);
		int id = n/p10%10;
		int k = 10 - n % 10;
		
		rof (i, id+1, 0)
			ans += dp[len][max (mx, i)][k].X,
			k = dp[len][max (mx, i)][k].Y;

		p10 *= 10;
		n = n / p10 * p10 - k;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
