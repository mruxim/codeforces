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

int n;
vector<int> adj[maxn];
int a[maxn];
vector<int> ans;

void dfs(int u, int par = -1, int on = 0, int off = 0) {
	if(a[u] ^ on) ans.pb(u), on ^= 1;
	for(int v: adj[u]) if(v != par)
		dfs(v, u, off, on);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	rep(i, n) cin >> a[i];
	rep(i, n) { int x; cin >> x; a[i] ^= x; }

	dfs(0);

	cout << sz(ans) << endl;
	for(int x: ans) cout << x+1 << endl;

	{ return 0; }
}

