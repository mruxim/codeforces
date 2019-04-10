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

const int mod = 1000000000 + 7;

const int maxn = 20 + 2;

int n;
int rev[maxn];
ll f[maxn];
ll s;

int powmod(int a, int b) {
	int res = 1;
	rep(i, 31) {
		if(b >> i & 1) res = res * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return res;
}

int C(ll a, int b) {
	if(a < b) return 0;
	int res = 1;
	for(ll k = a; k > a-b; k--) {
		res = res * (k % mod) % mod;
		res = res * (ll)rev[a - k + 1] % mod;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, maxn) rev[i] = powmod(i, mod-2);

	cin >> n >> s;
	rep(i, n) cin >> f[i];
	
	int ans = 0;

	rep(mask, 1<<n) {
		ll r = s;
		rep(i, n) if(mask >> i & 1) r -= f[i] + 1;
		int tmp = C(r+n-1, n-1);
		if(__builtin_popcount(mask) & 1)
			ans -= tmp;
		else
			ans += tmp;
		if(ans < 0) ans += mod;
		if(ans >= mod) ans -= mod;
	}

	cout << ans << endl;

	{ return 0; }
}

