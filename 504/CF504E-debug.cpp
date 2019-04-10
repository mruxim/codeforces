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

const int maxn = 600000 + 100;
const int maxlg = 20;
const int base = 7077;

ll pw[maxn];

int n, m;
string s;
vector<int> adj[maxn];
int dep[maxn];
int par[maxn][maxlg];
ll up[maxn][maxlg], dw[maxn][maxlg];

void dfs(int u, int parent, int depth) {
	dep[u] = depth;
	par[u][0] = parent;
	up[u][0] = dw[u][0] = s[u];
	fer(i, 1, maxlg) {
		par[u][i] = par[par[u][i-1]][i-1];
		up[u][i] = up[u][i-1] * pw[1<<(i-1)] + up[par[u][i-1]][i-1];
		dw[u][i] = dw[par[u][i-1]][i-1] * pw[1<<(i-1)] + dw[u][i-1];
	}
	
	for(int v: adj[u]) if(v != parent) dfs(v, u, depth+1);
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	rof(i, maxlg, 0) if(dep[par[v][i]] >= dep[u]) v = par[v][i];
	if(u == v) return u;
	rof(i, maxlg, 0) if(par[u][i] != par[v][i])
		u = par[u][i], v = par[v][i];
	return par[u][0];
}

int depkpar(int u, int depth) {
	rof(i, maxlg, 0) if(dep[par[u][i]] >= depth)
		u = par[u][i];
	return u;
}

int go(int a, int b) {
	if(dep[a] >= dep[b]) return par[a][0];
	if(depkpar(b, dep[a]) != a) return par[a][0];
	return depkpar(b, dep[a] + 1);
}

int naive(int a, int b, int c, int d) {
	int ans = 0;
	while(a != b && c != d) {
		if(s[a] != s[c]) return ans;
		a = go(a, b); c = go(c, d);
		ans++;
	}
	if(s[a] == s[c]) ans++;
	return ans;
}

int solve(int a, int b, int c, int d) {
	int x = lca(a, b);
	int y = lca(c, d);

	int ans = 0;

	rof(i, maxlg, 0) if((1<<i) <= min(dep[a] - dep[x], dep[c] - dep[y]) + 1)
		if(up[a][i] == up[c][i])
			ans += 1<<i, a = par[a][i], c = par[c][i];

	if(dep[a] >= dep[x] && dep[c] >= dep[y]) return ans;
	if(dep[a] < dep[x]) swap(a, c), swap(b, d), swap(x, y);
	assert(dep[c] < dep[y]);
	c = y;

	rof(i, maxlg, 0) if((1<<i) <= dep[d] - dep[y] && (1<<i) <= dep[a] - dep[x] + 1) {
		int pd = depkpar(d, dep[y] + (1<<i));
		if(up[a][i] == dw[pd][i])
			ans += 1<<i, a = par[a][i], y = pd;
	}

	if(dep[a] >= dep[x] || (dep[a] < dep[x] && x == b) || y == d) return ans;
	a = x;

	assert(depkpar(b, dep[a]) == a);
	assert(depkpar(d, dep[y]) == y);

	rof(i, maxlg, 0) if((1 << i) <= min(dep[b] - dep[x], dep[d] - dep[y])) {
		int pb = depkpar(b, dep[x] + (1<<i));
		int pd = depkpar(d, dep[y] + (1<<i));
		if(dw[pb][i] == dw[pd][i])
			ans += 1<<i, x = pb, y = pd;
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	pw[0] = 1;
	fer(i, 1, maxn) pw[i] = pw[i-1] * base;

	cin >> n;
//	cin >> s;
	s = string(n, ' '); rep(i, n) s[i] = rand() % 2 + 'a';

	rep(i, n-1) {
		int u, v;
//		cin >> u >> v; u--, v--;
		u = i+1, v = rand() % u;
		adj[u].pb(v), adj[v].pb(u);
	}

	adj[0].pb(n), adj[n].pb(0);
	dfs(n, n, 0);

	cin >> m;
	rep(z, m) {
		int a, b, c, d;
//		cin >> a >> b >> c >> d; a--, b--, c--, d--;
		srand(z * 45 + 453); a = rand() % n, b = rand() % n, c = rand() % n, d = rand() % n;

		if(solve(a, b, c, d) != naive(a, b, c, d)) {
			cout << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << " --> " << solve(a, b, c, d) << ' ' << naive(a, b, c, d) << endl;
			if(depkpar(a, dep[b]) == b) cerr << " ~~ b is a's ancestor!" << endl;
			if(depkpar(c, dep[d]) == d) cerr << " ~~ d is c's ancestor!" << endl;
			if(depkpar(b, dep[a]) == a) cerr << " ~~ a is b's ancestor!" << endl;
			if(depkpar(d, dep[c]) == c) cerr << " ~~ c is d's ancestor!" << endl;
		}
	}

	return 0;
}

