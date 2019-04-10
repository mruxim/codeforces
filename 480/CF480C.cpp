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

const int mod = 1000000007;
const int maxn = 5000 + 100;

int n, a, b, k;
int dp[maxn], odp[maxn];

inline void addto(int &x, int y) {
	x += y;
	if(x < 0) x += mod;
	if(x >= mod) x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> a >> b >> k;
	a--, b--;

	dp[a] = 1;

	rep(z, k) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		rep(i, n) if(abs(i-b) >= 2) {
			if(i < b)
				addto(dp[max(0, 2 * i - b + 1)], odp[i]), addto(dp[b], -odp[i]);
			else
				addto(dp[b+1], odp[i]), addto(dp[min(n, 2 * i - b)], -odp[i]);
			addto(dp[i], -odp[i]);
			addto(dp[i+1], odp[i]);
		}

		int cur = 0;
		rep(i, n) {
			addto(cur, dp[i]);
			dp[i] = cur;
		}
	}

	int ans = 0;
	rep(i, n) addto(ans, dp[i]);

	cout << ans << endl;

	return 0;
}

