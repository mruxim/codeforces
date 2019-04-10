// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000 * 1000 * 1000 + 7;
const int maxa = 1000000;

int p10[10];
int p2[maxa];

int n;
int cnt[maxa];
int sum[maxa];
int sum2[maxa];
int dp[maxa];

void addto(int &x, int y) {
	x += y;
	if(x < 0) x += mod;
	if(x >= mod) x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	p10[0] = 1;
	fer(i, 1, 10) p10[i] = p10[i-1] * 10;

	p2[0] = 1;
	fer(i, 1, maxa) p2[i] = p2[i - 1] * 2 % mod;

	cin >> n;
	rep(i, n) { int x; cin >> x; cnt[x]++; }

	rep(x, maxa) sum[x] = x * (ll)cnt[x] % mod;
	rep(x, maxa) sum2[x] = x * (ll)x % mod * cnt[x] % mod;

	rep(i, 6) rof(x, maxa, 0) if(x / p10[i] % 10 != 0) cnt[x - p10[i]] += cnt[x];
	rep(i, 6) rof(x, maxa, 0) if(x / p10[i] % 10 != 0) addto(sum[x - p10[i]], sum[x]);
	rep(i, 6) rof(x, maxa, 0) if(x / p10[i] % 10 != 0) addto(sum2[x - p10[i]], sum2[x]);

	ll ans = 0;

	rof(x, maxa, 0) {
		if(cnt[x] == 1)
			dp[x] = sum2[x];
		else if(cnt[x] > 1)
			dp[x] = (sum[x] * (ll)sum[x] + sum2[x]) % mod * p2[cnt[x] - 2] % mod;

		int cur = 0;
		rep(mask, 1 << 6) {
			int mul = -((__builtin_popcount(mask) & 1) * 2 - 1);
			int y = x;
			bool ok = true;
			rep(i, 6) if((mask >> i & 1)) { if(x / p10[i] % 10 != 9) y += p10[i]; else ok = false; }
			if(ok) addto(cur, dp[y] * mul);
		}

		ans ^= cur * (ll)x;
	}

	cout << ans << endl;
	return 0;
}

