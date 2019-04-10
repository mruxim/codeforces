// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 200000 + 100;

int n;
int a[maxn], b[maxn];

int mpow(int b, int p) {
	int res = 1;
	for(; p; p >>= 1, b = b * (ll)b % mod)
		if(p & 1) res = res * (ll)b % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	int s = 1;
	while(n % 2 == 0 || n / 2 % 2 == 1) {
		fill(b, b + n - 1, 0);
		rep(i, n - 1) {
			b[i] = a[i] + s * a[i + 1];
			if(b[i] >= mod) b[i] -= mod;
			if(b[i] < 0) b[i] += mod;
			s *= -1;
		}
		copy(b, b + n - 1, a);
		n--;
	}

	int mul = 1;
	int ans = 0;
	rep(i, n / 2 + 1) {
		ans = (ans + mul * (ll)a[i * 2]) % mod;
		mul = mul * (ll)mpow(i + 1, mod - 2) % mod;
		mul = mul * (ll)(n / 2 - i) % mod;
	}

	cout << ans << endl;

/*	f[1][0] = 1;
	fer(i, 2, n+1) {
		int s = (i / 2 % 2 ? 1 : -1);
		rep(j, i) {
			if(j < i - 1) f[i][j] += f[i-1][j];
			if(j) f[i][j] += (j % 2 ? s : -s) * f[i-1][j-1];
		}
	}

	rep(i, n) cout << f[n][i] << ' '; cout << endl;
*/
	return 0;
}

