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

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000+7;
const int maxn = 50 + 5;

int C[maxn][maxn];
int dp[maxn][maxn][2];

int calc (int n, int k, int p, int rt = true)
{
	if (n == 0) return k == 0 && p == 1;

	int &ret = dp[n][k][p];
	if (ret != -1) return ret;
	ret = 0;

	if (p == 0)
	{
		fer (ln, 1, n-1) fer (lk, 0, k+1)
		{
			int rn = n-ln-1; int rk = k-lk;
			int mul = C[n-1][ln];
			ret += calc (ln, lk, 1) * (ll)calc (rn, rk, 1) % mod * mul % mod; ret %= mod;
		}
		if (ret & 1) ret = (ret+mod) / 2; else ret /= 2;
		ret += calc (n-1, k, 1); ret %= mod;
	}
	else
	{
		fer (ln, 1, n-1) fer (lk, 0, k)
		{
			int rn = n-ln-1; int rk = k-lk-1;
			int mul = C[n-1][ln];
			ret += calc (ln, lk, 0) * (ll)calc (rn, rk, 1) % mod * mul % mod; ret %= mod;
			ret += calc (ln, lk, 1) * (ll)calc (rn, rk, 0) % mod * mul % mod; ret %= mod;
			ret += calc (ln, lk, 0) * (ll)calc (rn, rk, 0) % mod * mul % mod; ret %= mod;
		}
		if (ret & 1) ret = (ret+mod) / 2; else ret /= 2;
		ret += calc (n-1, k-1, 0); ret %= mod;
	}

	if (rt) ret = ret * (ll)n % mod;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	rep (i, maxn)
	{
		C[i][0] = C[i][i] = 1;
		fer (j, 1, i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	int n, k;
	cin >> n >> k;

	memset (dp, -1, sizeof dp);
	cout << (calc (n, k, 0, false) + calc (n, k, 1, false)) % mod << endl;

	{ return 0; }
}

