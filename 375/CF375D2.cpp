// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 * 1000 + 1000;

int n, m;
int o_color[maxn], color[maxn];
vector<int> adj[maxn], child[maxn];
vector<pii> query[maxn];
int ans[maxn];

int subs[maxn], st[maxn], ed[maxn], now;

int cnt[maxn], sum[maxn];

void dfs_size(int u, int par = -1) {
	color[now] = o_color[u];
	st[u] = now++;
	subs[u] = 1;
	for(int v: adj[u]) if(v != par)
		dfs_size(v, u),
		subs[u] += subs[v],
		child[u].pb (v);
	ed[u] = now;
}

inline void add_color(int col) { cnt[col]++; sum[cnt[col]]++; }
inline void rem_color(int col) { sum[cnt[col]]--; cnt[col]--; }

void dfs(int u) {
	int heavy = -1;
	for(int v: child[u])
		if(heavy == -1 || subs[heavy] < subs[v])
			heavy = v;

	for(int v: child[u]) if(v != heavy) {
		dfs(v);
		fer(id, st[v], ed[v]) rem_color(color[id]);
	}
	
	if (heavy != -1) dfs(heavy);
	int L = (heavy != -1) ? st[heavy] : st[u];
	int R = (heavy != -1) ? ed[heavy] : st[u];
	fer(id, st[u], L) add_color(color[id]);
	fer(id, R, ed[u]) add_color(color[id]);
	
	for(pii q: query[u]) ans[q.Y] = sum[q.X];
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep(i, n) cin >> o_color[i], o_color[i]--;
	rep(i, n-1) { int u, v; cin >> u >> v; u--, v--; adj[u].pb(v), adj[v].pb(u); }
	rep(i, m) { int u, k; cin >> u >> k; u--; query[u].pb(pii(k, i)); }

	dfs_size(0);
	dfs(0);

	rep(i, m) cout << ans[i] << endl;

	{ int _; cin >> _; return 0; }
}

