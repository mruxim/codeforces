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

const int maxn = 100000 + 100;
const int maxlg = 17 + 1;

int n;
vector<int> adj[maxn];
int par[maxlg][maxn];
int dep[maxn];
int fd[maxn];
int ud[maxlg][maxn], du[maxlg][maxn];

void dfs(int u, int parent = 0, int depth = 0) {
	par[0][u] = parent;
	dep[u] = depth;
	fer(i, 1, maxlg) par[i][u] = par[i-1][par[i-1][u]];

	fd[u] = 0;

	for(int v: adj[u]) if(v != parent) {
		dfs(v, u, depth + 1);
		smax(fd[u], fd[v] + 1);
	}
}

void dfs2(int u) {

	fer(i, 1, maxlg) {
		ud[i][u] = max(ud[i-1][u], ud[i-1][par[i-1][u]] + (1 << (i-1)));
		du[i][u] = max(du[i-1][u], ud[i-1][par[i-1][u]] + (1 << (i-1))); // ??????????
	}

	vector<int> lft(sz(adj[u]), 0), rgt(sz(adj[u]), 0);
	fer(i, 1, sz(adj[u])) lft[i] = max(lft[i-1], fd[adj[u][i-1]]);
	rof(i, sz(adj[u])-1, 0) rgt[i] = max(rgt[i+1], fd[adj[u][i+1]]);

	rep(i, sz(adj[u])) {
		ud[0][adj[u][i]] = du[0][adj[u][i]] = 1 + max(lft[i], rgt[i]);
		dfs2(adj[u][i]);
	}
}

int kth_parent(int u, int k) {
	rep(i, maxlg) if(k >> i & 1) u = par[i][u];
	return u;
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	rof(i, maxlg, 0) if(dep[u] - (1 << i) >= dep[v]) u = par[i][u];
	if(u == v) return u;
	rof(i, maxlg, 0) if(par[i][u] != par[i][v])
		u = par[i][u], v = par[i][v];
	return par[0][u];
}

int kup(int u, int k) {
	int res = 0;
	int dis = 0;
	rep(i, maxlg) if(k >> i & 1) {
		smax(res, ud[i][u] + dis);
		dis += 1 << i;
		u = par[i][u];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	dfs(0);
	dfs2(0);

	int m;
	for(cin >> m; m--; ) {
		int u, v; cin >> u >> v; u--, v--;
		if(dep[u] < dep[v]) swap(u, v);
		int lc = lca(u, v);
		int dis = dep[u] + dep[v] - 2 * dep[lc];
		int dis1 = (dis-1) / 2;
		int dis2 = dis - dis1;

		int w = kth_parent(u, dis1);
		assert(w != 0);

		ll ans = fd[u];
		smax(ans, kup(u, dis1));

		if(v != lc) smax(ans, max(fd[v], kup(v, dep[v] - dep[lc] - 1)));

		cout << ans << endl;
	}


	{ return 0; }
}

