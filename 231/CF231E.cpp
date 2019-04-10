// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m, q;
vector <int> adj[maxn];
int mark[maxn];
int path[maxn], plen = 0;
int cyc[maxn];
int par[maxn][18], dep[maxn];
int sum[maxn];
int ans[maxn];

void dfs(int v, int par) {
	if(mark[v]) return;
	mark[v] = 1;
	path[plen++] = v;
	cyc[v] = -1;


	rep(i, sz(adj[v])) {
		int u = adj[v][i];
		dfs(u, v);
		if(mark[u] == 1 && u != par) {
			rof(k, plen, 0) {
				cyc[path[k]] = u;
				if(path[k] == u) break;
				rep(j, sz(adj[path[k]]))
					adj[u].push_back(adj[path[k]][j]);
			}
		}
	}

	plen--;
	mark[v] = 2;
}

void dfs2(int v, int parent) {
	v = (cyc[v] == -1 ? v : cyc[v]);
	if(mark[v]) return;
	mark[v] = 1;
	if(v != 0) dep[v] = dep[parent] + 1;
	sum[v] = sum[parent] + (cyc[v] != -1 ? 1 : 0);
	par[v][0] = parent;
	fer(i, 1, 18) par[v][i] = par[par[v][i-1]][i-1];
	rep(i, sz(adj[v])) {
		int u = adj[v][i];
		if(cyc[u] == v) continue;
		dfs2(u, v);
	}
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	rof(i, 18, 0)
		if(dep[par[y][i]] >= dep[x])
			y = par[y][i];
	if(x == y) return x;
	rof(i, 18, 0)
		if(par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	return par[x][0];
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0, -1);
	memset(mark, 0, sizeof mark);
	dfs2(0, 0);

	ans[0] = 1;
	fer(i, 1, maxn) ans[i] = ans[i-1] * 2 % 1000000007;

	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if(cyc[x] != -1) x = cyc[x];
		if(cyc[y] != -1) y = cyc[y];
		int g = lca(x, y);
		int r = sum[x] + sum[y] - 2 * sum[g] + (cyc[g] != -1 ? 1 : 0);
		cout << ans[r] << endl;
	}

	{ int _; cin >> _; }
	return 0;
}
