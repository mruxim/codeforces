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

const int maxn = 10 + 2;
const int maxk = 1000 + 10;

int n, m, k, w;
char a[maxk][maxn][maxn];
ll ans;
vector<pair<int, pii>> e;
int par[maxk];
vector<int> adj[maxk];

int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
bool merge(int x, int y) {
	x = root(x), y = root(y);
	if(x == y) return false;
	par[x] = y;
	return true;
}

void dfs(int u, int p) {
	par[u] = p;
	if(u) cout << u << ' ' << p << endl;
	for(int v: adj[u]) if(v != p)
		dfs(v, u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k >> w;
	rep(p, k) {
		rep(i, n) cin >> a[p][i];

		e.pb({n*m, {p+1, 0}});
		rep(q, p) {
			int tmp = 0;
			rep(i, n) rep(j, m) tmp += (a[p][i][j] != a[q][i][j]);
			tmp *= w;
			e.pb({tmp, {p+1, q+1}});
		}
	}

	sort(all(e));
	memset(par, -1, sizeof par);
	for(auto ee: e) {
		if(merge(ee.Y.X, ee.Y.Y))
			adj[ee.Y.X].pb(ee.Y.Y), adj[ee.Y.Y].pb(ee.Y.X),
			ans += ee.X;
	}

	cout << ans << endl;
	dfs(0, -1);

	{ return 0; }
}

