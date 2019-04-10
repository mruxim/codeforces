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

const int maxn = 5000 + 100;

int n;
int a[maxn];
int dp[maxn][maxn];
int mn[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	rep(e, n+1) rof(s, e, 0) {
		if(e - s >= 2 && a[mn[s+1][e]] < a[s])
			mn[s][e] = mn[s+1][e];
		else
			mn[s][e] = s;

		dp[s][e] = e - s;
		int g = max(s ? a[s-1] : 0, e<n ? a[e] : 0);
		if(g > a[mn[s][e]]) continue;

		smin(dp[s][e], a[mn[s][e]] - g + dp[s][mn[s][e]] + dp[mn[s][e]+1][e]);
	}

	cout << dp[0][n] << endl;

	{ return 0; }
}

