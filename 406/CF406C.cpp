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

int n, m;
vector<int> adj[maxn];
int mark[maxn];
vector<int> x, y, z;

bool dfs(int u, int par = -1) {
	mark[u] = 1;
	vector<int> e;
	for(int v: adj[u]) if(v != par) {
		if(mark[v] == 1) e.pb(v);
		else if(!mark[v]) {
			bool tmp = dfs(v, u);
			if(!tmp) e.pb(v);
		}
	}

	rep(i, sz(e)/2) x.pb(e[2*i]), y.pb(u), z.pb(e[2*i+1]);
	mark[u] = 2;
	if(sz(e) % 2 == 0) return false;
	x.pb(e.back()), y.pb(u), z.pb(par);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	if(m % 2) { cout << "No solution" << endl; return 0; }

	dfs(0);

	rep(i, sz(x)) cout << x[i]+1 << ' ' << y[i]+1 << ' ' << z[i]+1 << endl;

	{ return 0; }
}

