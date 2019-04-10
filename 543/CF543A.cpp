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

const int maxn = 500 + 10;

int n, m, b, mod;
int a[maxn];
int dp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> b >> mod;
	rep(i, n) cin >> a[i];

	dp[0][0] = 1;
	rep(z, n) {
		int x = a[z];
		fer(i, 1, m+1)
			fer(v, x, b+1) {
				dp[i][v] += dp[i-1][v-x];
				if(dp[i][v] >= mod) dp[i][v] -= mod;
			}
	}

	int ans = 0;
	rep(i, b+1) ans = (ans + dp[m][i]) % mod;
	cout << ans << endl;

	return 0;
}

