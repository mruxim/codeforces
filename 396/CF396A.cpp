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
const int maxn = 500 + 10;
const int maxa = maxn * 40;
const int CTV = 100000;

int n;
int pw[CTV];
map<int, int> pw2;
int f[maxa], rf[maxa];

int powmod(int a, int b) {
	int ret = 1;
	rep(i, 31) {
		if(b >> i & 1) ret = ret * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return ret;
}

int C(int a, int b) {
	return f[a] * (ll)rf[b] % mod * rf[a-b] % mod;
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) {
		int a; cin >> a;
		for(int i = 2; i*i <= a; i++)
			while (a % i == 0) a /= i, pw[i]++;
		if (a > 1) (a < CTV ? pw[a] : pw2[a])++;
	}

	f[0] = rf[0] = 1;
	fer(i, 1, maxa)
		f[i] = f[i-1] * (ll)i % mod,
		rf[i] = powmod(f[i], mod-2);

	int ans = 1;
	rep(i, CTV) ans = ans * (ll)C(pw[i]+n-1, n-1) % mod;
	for(auto it: pw2) ans = ans * (ll)C(it.second+n-1, n-1) % mod;

	cout << ans << endl;


	{ return 0; }
}

