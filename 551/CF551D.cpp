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

ll n, k;
int cnt, l, mod;
int C[100][100];

int modpow(int a, ll p) {
	int r = 1;
	while(p) {
		if(p & 1) r = r * (ll)a % mod;
		a = a * (ll)a % mod;
		p >>= 1;
	}
	return r;
}

pii fib(ll k) {
	if(k <= 1) return pii((k+1) % mod, (k+2) % mod);
	if(k & 1) {
		pii p = fib(k-1);
		return pii(p.Y, p.X+p.Y);
	} else {
		pii p = fib(k/2-1);
		return pii(p.X*(2LL*p.Y-p.X+mod) % mod, (p.X*(ll)p.X + p.Y*(ll)p.Y) % mod);
	}
}

int f, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k >> l >> mod;
	cnt = __builtin_popcountll(k);

	if(cnt > l) {
		cout << 0 << endl;
		return 0;
	}

	f = fib(n).X;
	d = modpow(2, n);

	cout << f << ' ' << d << ' ' << cnt << ' ' << endl;

	rep(i, 100) {
		C[i][0] = C[i][i] = 1;
		fer(j, 1, i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	int ans = 1;
	rep(i, cnt) ans = ans * (ll)(d-f+mod) % mod;
	rep(i, l-cnt) ans = ans * (ll)f % mod;
	cout << ans << endl;

	return 0;
}

