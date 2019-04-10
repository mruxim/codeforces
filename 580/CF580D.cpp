// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 18 + 1;

int n, m, k;
int a[maxn];
int g[maxn][maxn];
ll dp[1<<maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	rep(i, n) cin >> a[i];
	rep(i, k) {
		int u, v, c; cin >> u >> v >> c; u--, v--;
		g[u][v] = c;
	}

	ll ans = 0;
	rep(mask, 1<<n) rep(last, n) if((mask >> last) & 1) {
		int tmask = mask ^ (1 << last);
		rep(prv, n) if((tmask >> prv) & 1)
			smax(dp[mask][last], dp[tmask][prv] + g[prv][last]);
		dp[mask][last] += a[last];
		if(__builtin_popcount(mask) == m)
			smax(ans, dp[mask][last]);
	}

	cout << ans << endl;
	return 0;
}

