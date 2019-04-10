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

int n, m;
vector<int> adj[maxn];
char vis[maxn], act[maxn];
int now, ind[maxn], low[maxn];
int comp[maxn], cs[maxn], cn;
int st[maxn], top;
vector<int> cadj[maxn];

void dfs(int u) {
	act[u] = vis[u] = 1;
	ind[u] = low[u] = now++;
	st[top++] = u;

	for(int v: adj[u])
		if(vis[v] == 0)
			dfs(v), smin(low[u], low[v]);
		else if(act[v])
			smin(low[u], ind[v]);

	if(ind[u] == low[u]) {
		do {
			top--;
			comp[st[top]] = cn;
			cs[cn]++;
			act[st[top]] = 0;
		} while(st[top] != u);
		cn++;
	}
	vis[u] = 2;
}

bool mark[maxn];

pii dfsc(int cu) {
	if(mark[cu]) return {0, 0};
	mark[cu] = true;
	int cnt = cs[cu], mx = cs[cu];
	for(int cv: cadj[cu]) {
		pii tmp = dfsc(cv);
		cnt += tmp.X, smax(mx, tmp.Y);
	}
	return {cnt, mx};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
	}

	rep(i, n) if(!vis[i]) dfs(i);

	rep(u, n) for(int v: adj[u]) if(comp[u] != comp[v])
		cadj[comp[u]].pb(comp[v]), cadj[comp[v]].pb(comp[u]);

	int ans = 0;
	rep(i, cn) if(!mark[i]) {
		pii tmp = dfsc(i);
		ans += tmp.X;
		if(tmp.Y == 1) ans--;
	}

	cout << ans << endl;

	return 0;
}

