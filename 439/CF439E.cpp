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

const int mod = 1000000000+7;
const int maxn = 100000 + 100;

int powmod(int a, int p) {
	int r = 1;
	rep(i, 31) {
		if(p >> i & 1) r = r * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return r;
}

int f[maxn], rf[maxn];
vector<int> dv[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	f[0] = rf[0] = 1;
	fer(i, 1, maxn) f[i] = f[i-1] * (ll)i % mod, rf[i] = powmod(f[i], mod-2);

	fer(i, 2, maxn) if(sz(dv[i]) == 0)
		for(int j = i; j < maxn; j += i) dv[j].pb(i);

	int q;
	q = 100000;
	//cin >> q;
	while(q--) {
		int n, t;
		n = 60060, t = 1;
	//	cin >> n >> t;
		int ans = 0;
		rep(mask, 1 << sz(dv[n])) {
			int d = 1, c = 1;
			rep(i, sz(dv[n])) if(mask >> i & 1)
				d *= dv[n][i], c = -c;
			d = n/d;
			if(d >= t)
				ans = (ans + c * f[d-1] * (ll)rf[t-1] % mod * rf[d-t] % mod + mod) % mod;
		}

		cout << ans << endl;
	}

	{ return 0; }
}

