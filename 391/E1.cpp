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

const int maxn = 1000 + 100;

ll n[3];
int d[3][maxn][maxn];
int sum[3][maxn];
int c[3];
vector<int> a[3][maxn];

void dfs (int u, vector<int> adj[maxn], int dis[maxn], int dep = 0) {
	dis[u] = dep;
	for (int v: adj[u]) if (dis[v] == -1)
		dfs (v, adj, dis, dep+1);
}

int main() {
	ios_base::sync_with_stdio (false);

	rep (i, 3) cin >> n[i];
	rep (i, 3) rep (j, n[i]-1) {
		int u, v; cin >> u >> v; u--, v--;
		a[i][u].pb (v), a[i][v].pb (u);
	}

	ll add = 0;

	rep (i, 3) rep (j, n[i]) {
		memset (d[i][j], -1, sizeof d[i][j]);
		dfs (j, a[i], d[i][j]);
		rep (k, n[i]) sum[i][j] += d[i][j][k];
		add += sum[i][j];
		if (sum[i][j] >= sum[i][c[i]]) c[i] = j;
	}
	add /= 2;
	ll ans = 0;
	rep (i, 3) rep (u, n[i]) rep (v, n[i]) {
		int mid = d[i][u][v] + 2;
		int j = (i+1) % 3, k = (i+2) % 3;
		ll cur = 0;
		cur += sum[j][c[j]] * n[i] + n[j] * sum[i][u] + n[i] * n[j];
		cur += sum[k][c[k]] * n[i] + n[k] * sum[i][v] + n[i] * n[k];
		cur += sum[j][c[j]] * n[k] + n[j] * sum[k][c[k]] + mid * n[j] * (ll)n[k];
		smax (ans, cur);
	}

	cout << ans + add << endl;
	{ return 0; }
}

