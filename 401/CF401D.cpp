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

const int maxk = 18;
const int maxm = 100 + 5;

ll n;
int m;

int powrem[maxk];

int k;
int digit[maxk];

ll dp[1<<maxk][maxm];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	for(k = 0; n; n /= 10) digit[k++] = n % 10;

	powrem[0] = 1;
	fer(i, 1, maxk) powrem[i] = powrem[i-1] * 10 % m;

	dp[0][0] = 1;

	fer(mask, 1, 1<<k) rep(bit, k) if(mask >> bit & 1) {
		int oldmask = mask ^ (1 << bit);
		if(oldmask == 0 && digit[bit] == 0) continue;
		int cur = digit[bit] * powrem[k - __builtin_popcount(mask)] % m;
		rep(rem, m) {
			int oldrem = rem - cur;
			if(oldrem < 0) oldrem += m;
			dp[mask][rem] += dp[oldmask][oldrem];
		}
	}

	ll ans = dp[(1<<k)-1][0];

	rep(dig, 10) {
		int cnt = count(digit, digit+k, dig);
		rep(i, cnt) ans /= i+1;
	}

	cout << ans << endl;

	{ return 0; }
}

