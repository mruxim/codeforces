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

int n, OL, OW;
vector<pii> adj[maxn];
bool mark[maxn];
int sub_size[maxn];
ll ans;
int fen[maxn];

int get_size(int u, int par = -1) {
	int ret = 1;
	for(pii vw: adj[u]) if(vw.X != par && !mark[vw.X]) ret += get_size(vw.X, u);
	return sub_size[u] = ret;
}

int find_center(int u, int comp_size, int par = -1) {
	int max_sub = comp_size - sub_size[u];
	for(pii vw: adj[u]) if(vw.X != par && !mark[vw.X]) {
		int tmp = find_center(vw.X, comp_size, u);
		if(tmp != -1) return tmp;
		smax(max_sub, sub_size[vw.X]);
	}
	if(max_sub <= comp_size / 2) return u;
	return -1;
}

vector<pii> store;

void dfs_gen(int u, int par, int curL = 0, int curW = 0) {
	if(mark[u] || curL > OL || curW > OW) return;
	store.pb({curW, curL});
	for(pii vw: adj[u]) if(vw.X != par) dfs_gen(vw.X, u, curL + 1, curW + vw.Y);
}

inline void add_fen(int pos, int val) {
	for(pos++; pos < maxn; pos += pos & -pos) fen[pos] += val;
}

inline int get_fen(int pos) {
	int ret = 0;
	for(pos = max(pos, 0); pos; pos -= pos & -pos) ret += fen[pos];
	return ret;
}

ll cnt(int u, int par, int L, int W) {
	store.clear();
	dfs_gen(u, par);
	sort(all(store));

	ll ret = 0;
	int pos = 0;
	rof(i, sz(store), 0) {
		while(pos < sz(store) && store[pos].X + store[i].X <= W)
			add_fen(store[pos].Y, 1), pos++;
		ret += get_fen(L - store[i].Y + 1);
	}
	while(pos--) add_fen(store[pos].Y, -1);

	return ret;
}

void solve(int u) {
	int comp_size = get_size(u);
	u = find_center(u, comp_size);

	ans += cnt(u, -1, OL, OW) - 1;
	for(pii vw: adj[u]) if(!mark[vw.X]) ans -= cnt(vw.X, u, OL-2, OW-2*vw.Y);

	mark[u] = true;
	for(pii vw: adj[u]) if(!mark[vw.X]) solve(vw.X);
}	

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> OL >> OW;
	fer(u, 1, n) {
		int v, w; cin >> v >> w; v--;
		adj[u].pb({v, w}); adj[v].pb({u, w});
	}

	solve(0);

	cout << ans / 2 << endl;

	{ return 0; }
}

