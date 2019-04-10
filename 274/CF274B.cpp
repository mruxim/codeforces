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
typedef pair<ll, ll> pll;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
vector<int> adj[maxn];
int val[maxn];

pll dfs(int u, int par = -1) {
	pll ret = {0, 0};
	for(int v: adj[u]) if (v != par) {
		pll tmp = dfs (v, u);
		smin (ret.X, tmp.X);
		smax (ret.Y, tmp.Y);
	}
	ll need = val[u] - (ret.X + ret.Y);
	if (need > 0) ret.Y += need;
	else ret.X += need;
	return ret;
}


int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	rep(i, n) cin >> val[i];

	pll ans = dfs(0);

	cout << -ans.X + ans.Y << endl;

	{ return 0; }
}

