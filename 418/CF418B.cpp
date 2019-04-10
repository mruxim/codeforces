// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 + 10;
const int maxm = 20 + 1;

int n, m, b;
int x[maxn], k[maxn], t[maxn];
int id[maxn];
ll dp[1<<maxm];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> b;
	rep(i, n) {
		int c;
		cin >> x[i] >> k[i] >> c;
		rep(j, c) {
			int p; cin >> p; p--;
			t[i] |= 1 << p;
		}
	}

	iota(id, id+n, 0);
	sort(id, id+n, [](int p, int q) { return make_pair(k[p], p) < make_pair(k[q], q); } );

	memset(dp, 50, sizeof dp);
	dp[0] = 0;

	ll ans = 2e18;
	rep(i, n) {
		int p = id[i];
		int xx = x[p], kk = k[p], tt = t[p];
		rep(mask, 1<<m) smin(dp[mask | tt], dp[mask] + xx);
		smin(ans, dp[(1 << m) - 1] + kk * (ll)b);
	}

	cout << (ans == (ll)2e18 ? -1ll : ans) << endl;

	{ return 0; }
}

