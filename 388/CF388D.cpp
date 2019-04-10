
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>

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

int C[111][111];

int F (int n, int p) {
	int ret = 0;
	rep (minp, n-p)
		ret += (1 << minp) * (ll)C[n-minp-1][p-1] % mod, ret %= mod;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	rep (i, 111) {
		C[i][i] = C[i][0] = 1;
		fer (j, 1, i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}

	int k;
	cin >> k;
	int ans = 0;
	rof (b, 30, 0) if (k >> b & 1) {
		int add = __builtin_popcount (k >> (b+1));
		rep (j, b) ans += F (add + b, add + j) * C[b][j] % mod, ans %= mod;
	}

	cout << ans << endl;

	{ return 0; }
}

/*
 * 000
 * 011
 * 101
 * 110
 *
 * 000
 * 001
 * 110
 * 111
 *
 * 000
 * 010
 * 101
 * 111
*/








