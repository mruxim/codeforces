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

const int maxn = 300000 + 100;

int n, m, q;
vector<int> adj[maxn];
bool mark[maxn];
int par[maxn], dia[maxn];
int tmpdia;

int root(int x) {
	return par[x] < 0 ? x : par[x] = root(par[x]);
}

void merge(int x, int y) {
	x = root(x), y = root(y);
	if(x == y) return;
	if(par[x] < par[y]) swap(x, y);
	par[y] += par[x];
	par[x] = y;
	smax(dia[y], max(1 + (dia[x]+1)/2 + (dia[y]+1)/2, dia[x]));
}

int dfs(int u) {
	mark[u] = true;
	int mx = 0;
	for(int v: adj[u]) if(!mark[v]) {
		merge(u, v);
		int cur = dfs(v);
		smax(tmpdia, mx + cur + 1);
		smax(mx, cur + 1);
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> q;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset(par, -1, sizeof par);

	rep(i, n) if(!mark[i]) {
		tmpdia = 0;
		dfs(i);
		dia[root(i)] = tmpdia;
	}

	rep(i, q) {
		int tp; cin >> tp;
		if(tp == 1) {
			int u; cin >> u; u--;
			cout << dia[root(u)] << endl;
		} else {
			int u, v; cin >> u >> v; u--, v--;
			merge(u, v);
		}
	}

	return 0;
}

