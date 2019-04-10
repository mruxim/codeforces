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

const int maxn = 1000 + 10;

int n, m, a, b;
char s[maxn][maxn];
int cost[maxn][2];
int dp[maxn][2][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> a >> b;
	rep(i, n) cin >> s[i];

	rep(i, n) rep(j, m) cost[j][s[i][j] == '.' ? 0 : 1]++;

	memset(dp, 50, sizeof dp);
	dp[0][0][0] = dp[0][1][0] = 0;
	fer(i, 1, m+1) fer(j, 1, i+1) rep(c, 2) {
		smin(dp[i][c][j], dp[i-1][c][j-1] + cost[i-1][c]);
		if(a <= j && j <= b)
			smin(dp[i][c^1][0], dp[i][c][j]);
	}

	cout << min(dp[m][0][0], dp[m][1][0]) << endl;

	return 0;
}

