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

const int mod = 1000000007;

const int maxn = 1000000 + 100;
const int maxb = 20;

int n;
int dp[1<<maxb];
int p2[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) { int x; cin >> x; dp[(1<<maxb)-1-x]++; }

	rep (i, maxb) rof (mask, 1<<maxb, 0)
		if (mask >> i & 1) dp[mask] += dp[mask ^ (1<<i)];

	p2[0] = 1;
	fer(i, 1, maxn) p2[i] = p2[i-1] * 2 % mod;

	int ans = 0;

	rep(mask, 1 << maxb) {
		int tmp = p2[dp[mask]];
		if(__builtin_popcount(mask) % 2 == 0)
			ans += tmp;
		else
			ans -= tmp;
		if(ans >= mod) ans -= mod;
		if(ans < 0) ans += mod;
	}

	cout << ans << endl;

	{ return 0; }
}

