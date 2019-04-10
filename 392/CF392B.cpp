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

const int maxn = 40 + 5;

int n;
int cost[3][3];
ll dp[maxn][3][3];

int main() {
	ios_base::sync_with_stdio (false);

	rep (i, 3) rep (j, 3) cin >> cost[i][j];
	cin >> n;

	fer (k, 1, n+1) rep (i, 3) rep (j, 3) if (i != j)
		dp[k][i][j] = min (dp[k-1][i][3-i-j] + cost[i][j] + dp[k-1][3-i-j][j],
						dp[k-1][i][j] + cost[i][3-i-j] + dp[k-1][j][i] + cost[3-i-j][j] + dp[k-1][i][j]);

	cout << dp[n][0][2] << endl;

	{ return 0; }
}

