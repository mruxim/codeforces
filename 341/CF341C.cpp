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

const int mod = 1000000000 + 7;

const int maxn = 2000 + 100;

int n;
int a[maxn];
bool mark[maxn];
int tot, common;

int C[maxn][maxn];
int fact[maxn];
int dp[maxn][maxn];

int f (int k)
{
	int ret = 0;
	for (int fx = 0; fx <= k; fx++)
	{
		int sgn = 1 - (fx % 2) * 2;
		ret += sgn * (C[k][fx] * (ll)fact[k-fx] % mod);
		if (ret >= mod) ret -= mod;
		if (ret < 0) ret += mod;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i], a[i]--;

	rep (i, n) if (a[i] >= 0) mark[a[i]] = true; else tot++;
	rep (i, n) if (a[i] < 0 && !mark[i]) common++;


	rep (i, maxn)
	{
		C[i][0] = C[i][i] = 1;
		fer (j, 1, i)
		{
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if (C[i][j] >= mod) C[i][j] -= mod;
		}
	}

	fact[0] = 1;
	fer (i, 1, maxn) fact[i] = fact[i-1] * (ll)i % mod;

	rep (i, tot+1) rep (j, i+1)
	{
		if (i == j)
			dp[i][j] = f (i);
		else if (j == 0)
			dp[i][j] = fact[i];
		else
			dp[i][j] = ((ll)(j-1) * (j>=2 ? dp[i-1][j-2] : 0) + (ll)(i-j) * dp[i-1][j-1]) % mod;
	}

	cout << dp[tot][common] << endl;

	{ int _; cin >> _; return 0; }
}
