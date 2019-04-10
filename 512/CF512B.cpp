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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = 1<<30;
const int maxn = 300 + 10;

int n;
int l[maxn];
int c[maxn];
int d[22], t;
int dp[1<<20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> l[i];
	rep(i, n) cin >> c[i];

	int ans = inf;
	rep(f, n) {
		int x = l[f];
		t = 0;
		for(int i = 2; i*i <= x; i++) if(x % i == 0) {
			d[t++] = i;
			while(x % i == 0) x /= i;
		}
		if(x > 1) d[t++] = x;

		rep(i, 1<<t) dp[i] = inf;
		dp[0] = 0;
		rep(i, n) {
			int mask = 0;
			rep(j, t) if(l[i] % d[j]) mask |= 1 << j;
			rep(j, 1<<t) smin(dp[j | mask], dp[j] + c[i]);
		}
		smin(ans, c[f] + dp[(1<<t)-1]);
	}

	if(ans < inf) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}

