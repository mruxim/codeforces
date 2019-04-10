// .... .... .....!
// P..... C.....!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxlog = 17 + 1;

int n, m;
bool good[maxn];

vector<pii> adj[maxn];
vector<pii> childs[maxn];
bool mark[maxn];

pii down[maxn];
pii glob[maxn];

int par[maxlog][maxn];
int dep[maxn];

int val[maxn];

pii combine(pii p, pii q, int v) {
	if(p.X == -1 && q.X == -1) return pii(-1, 0);
	if(p.X == -1) return q;
	if(q.X == -1) return p;
	if(p.Y == q.Y) return pii (v, p.Y);
	return(p.Y < q.Y) ? q : p;
}

void dfs_down(int v, int parent = 0, int depth = 0) {
	mark[v] = true;
	down[v] = pii(good[v] ? v : -1, 0);

	dep[v] = depth;
	par[0][v] = parent;
	fer(i, 1, maxlog) par[i][v] = par[i-1][par[i-1][v]];

	for(pii uw: adj[v]) if(!mark[uw.X]) {
		int u = uw.X, w = uw.Y;
		childs[v].pb(uw);

		dfs_down(u, v, depth + 1);

		down[v] = combine(down[v], pii (down[u].X, down[u].Y + w), v);
	}
}

void dfs_glob(int v, pii up = pii (-1, 0)) {
	glob[v] = combine(up, down[v], v);

	pii cur = (good[v] ? pii(v, 0) : pii(-1, 0));
	vector<pii> left;
	for(pii uw: childs[v]) {
		int u = uw.X, w = uw.Y;
		left.pb(cur);
		cur = combine(cur, pii(down[u].X, down[u].Y + w), v);
	}

	rof(i, sz(childs[v]), 0) {
		int u = childs[v][i].X, w = childs[v][i].Y;

		pii tmp = combine(up, left[i], v);

		dfs_glob(u, pii(tmp.X, tmp.Y + w));

		up = combine(up, pii(down[u].X, down[u].Y + w), v);
	}
}

int lca(int v, int u) {
	if(dep[v] > dep[u]) swap(v, u);

	rof(i, maxlog, 0)
		if(dep[v] <= dep[u] - (1 << i))
			u = par[i][u];

	rof(i, maxlog, 0)
		if(par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];

	return v == u ? v : par[0][v];
}

void relax(int v) {
	for(pii uw: childs[v]) {
		relax(uw.X);
		val[v] += val[uw.X];
	}
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m) {
		int x;
		cin >> x; x--;
		good[x] = true;
	}
	rep (i, n-1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].pb(pii(v, w));
		adj[v].pb(pii(u, w));
	}

	dfs_down(0);
	dfs_glob(0);

	rep(v, n) if(good[v]) {
		int u = lca(v, glob[v].X);
		val[v]++;
		val[glob[v].X]++;
		val[u]--;
		if(u != 0) val[par[0][u]]--;;
	}

	relax(0);

	pii ans = pii(-1, 0);
	rep(i, n) if(!good[i] && ans.X <= val[i])
			ans = pii(val[i], ans.X == val[i] ? ans.Y+1 : 1);

	cout << ans.X << ' ' << ans.Y << endl;

	{ int _; cin >> _; return 0; }
}
