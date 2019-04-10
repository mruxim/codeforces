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

const int maxn = 100000 + 100;
const int maxl = 17 + 2;

int n, m;
vector<int> adj[maxn];
int dep[maxn], sub[maxn];
int par[maxn][maxl];

void dfs(int u, int parent = 0, int depth = 0) {
	dep[u] = depth;
	par[u][0] = parent;
	fer(i, 1, maxl)
		par[u][i] = par[par[u][i-1]][i-1];

	sub[u] = 1;
	for(int v: adj[u]) if(v != parent) {
		dfs(v, u, depth+1);
		sub[u] += sub[v];
	}
}

int kthpar(int u, int k) {
	rof(i, maxl, 0) if(k >= (1 << i)) k -= 1 << i, u = par[u][i];
	return u;
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	rof(i, maxl, 0) if(dep[par[v][i]] >= dep[u]) v = par[v][i];
	if(u == v) return u;
	rof(i, maxl, 0)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0);

	cin >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		if(u == v) { cout << n << endl; continue; }
		int t = lca(u, v);
		int ut = dep[u] - dep[t];
		int vt = dep[v] - dep[t];

		if((ut + vt) % 2) { cout << 0 << endl; continue; }
		if(ut > vt) swap(u, v), swap(ut, vt);
		if(ut == vt) {
			cout << n - sub[kthpar(u, ut-1)] - sub[kthpar(v, vt-1)] << endl;
			continue;
		}
		int d = (ut + vt) / 2;
		cout << sub[kthpar(v, d)] - sub[kthpar(v, d-1)] << endl;
	}

	return 0;
}

