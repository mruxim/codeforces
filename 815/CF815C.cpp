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

const int maxn = 5000 + 10;

int n, b;
int c[maxn], d[maxn];
vector<int> child[maxn];
int sub[maxn];
int dp[maxn][2][maxn];

void dfs(int u) {
	sub[u] = 1;
	dp[u][0][0] = 0;
	dp[u][0][1] = c[u];
	dp[u][1][1] = d[u];
	for(int v: child[u]) {
		dfs(v);
		rep(i, sub[v] + 1) rof(j, sub[u] + 1, 0) {
				smin(dp[u][0][j + i], dp[u][0][j] + dp[v][0][i]);
				smin(dp[u][1][j + i], dp[u][1][j] + dp[v][1][i]);
			}
		sub[u] += sub[v];
	}
	rep(i, sub[u] + 1) smin(dp[u][1][i], dp[u][0][i]);

	cerr << " $$ " << u + 1 << " : ";
	rep(i, sub[u] + 1) cerr << i << " - " << dp[u][1][i] << " ## ";
	cerr << endl;
	cerr << " $$ " << u + 1 << " : ";
	rep(i, sub[u] + 1) cerr << i << " - " << dp[u][0][i] << " ## ";
	cerr << endl;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> b;
	rep(i, n) {
		cin >> c[i] >> d[i];
		d[i] = c[i] - d[i];
		if(i > 0) {
			int x; cin >> x; x--;
			child[x].pb(i);
		}
	}

	rep(i, n) rep(j, 2) rep(k, n + 1) dp[i][j][k] = b + 1;
	dfs(0);

	int res = 0;
	while(res <= n && dp[0][1][res] <= b) res++;
	res--;

	cout << res << endl;

	return 0;
}

