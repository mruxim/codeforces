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

ll n, m, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	if(n > m) swap(n, m);

	if(k > n + m - 2) { cout << -1 << endl; return 0; }

	ll ans = 0;

	rep(k1, (int)min(1000000LL, k+1)) {
		if(k1 <= n-1 && k-k1 <= m-1) smax(ans, (n / (k1+1)) * (m / (k-k1+1)));
		if(k1 <= m-1 && k-k1 <= n-1) smax(ans, (m / (k1+1)) * (n / (k-k1+1)));
	}

	fer(s, 1, 10000) {
		if(s <= n) {
			int k1 = n / s - 1;
			if(k1 < 1000000) continue;
			smax(ans, s * (ll)(m / (k-k1+1)));
		}
		if(s <= m) {
			int k1 = m / s - 1;
			if(k1 < 1000000) continue;
			smax(ans, s * (ll)(n / (k-k1+1)));
		}
	}

	cout << ans << endl;

	{ return 0; }
}

