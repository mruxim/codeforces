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
const int maxlg = 20;
const int base = 727;
const int mod = 1000000000+7;

ll pw[maxn];
ll pw2[maxn];

int n, m;
char s[maxn];
vector<int> adj[maxn];
int dep[maxn];
int par[maxn][maxlg];
ll up[maxn][maxlg], dw[maxn][maxlg];
int up2[maxn][maxlg], dw2[maxn][maxlg];

inline int nextInt() {
	register char ch;
	register int res;
	while((ch = getchar()) < '0');
	for(res = ch - '0'; (ch = getchar()) >= '0'; res = res * 10 + ch - '0');
	return res;
}

void writen(register int Q) {
	static char W[12], E;
	W[11] = '\n';
	for(W[0xA]=Q%0xA+0x30,Q/=0xA,E=0xA;Q;W[(int)--E]=Q%0xA+0x30,Q/=0xA);
	fwrite(W+E,0x1,0xC-E,stdout);
}

void dfs(int u, int parent, int depth) {
	dep[u] = depth;
	par[u][0] = parent;
	up[u][0] = dw[u][0] = s[u];
	up2[u][0] = dw2[u][0] = s[u];
	fer(i, 1, maxlg) {
		par[u][i] = par[par[u][i-1]][i-1];
		up[u][i] = up[u][i-1] * pw[1<<(i-1)] + up[par[u][i-1]][i-1];
		dw[u][i] = dw[par[u][i-1]][i-1] * pw[1<<(i-1)] + dw[u][i-1];
		dw[u][i] = dw[par[u][i-1]][i-1] * pw[1<<(i-1)] + dw[u][i-1];
		up2[u][i] = (up2[u][i-1] * pw2[1<<(i-1)] + up2[par[u][i-1]][i-1]) % mod;
		dw2[u][i] = (dw2[par[u][i-1]][i-1] * pw2[1<<(i-1)] + dw2[u][i-1]) % mod;
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

inline int depkpar(int u, int depth) {
	rof(i, maxlg, 0) if(dep[par[u][i]] >= depth) u = par[u][i];
	return u;
}

int solve(int a, int b, int c, int d) {
	int x = lca(a, b), y = lca(c, d);
	int ans = 0;

	rof(i, maxlg, 0) if((1<<i) <= min(dep[a] - dep[x], dep[c] - dep[y]) + 1)
		if(up[a][i] == up[c][i] && up2[a][i] == up2[c][i])
			ans += 1<<i, a = par[a][i], c = par[c][i];

	if(dep[a] >= dep[x] && dep[c] >= dep[y]) return ans;
	if(dep[a] < dep[x]) swap(a, c), swap(b, d), swap(x, y);
	c = y;

	rof(i, maxlg, 0) if((1<<i) <= dep[d] - dep[y] && (1<<i) <= dep[a] - dep[x] + 1) {
		int pd = depkpar(d, dep[y] + (1<<i));
		if(up[a][i] == dw[pd][i] && up2[a][i] == dw2[pd][i])
			ans += 1<<i, a = par[a][i], y = pd;
	}

	if(dep[a] >= dep[x] || (dep[a] < dep[x] && x == b) || y == d) return ans;
	a = x;
	
	rof(i, maxlg, 0) if((1<<i) <= min(dep[b] - dep[x], dep[d] - dep[y])) {
		int pb = depkpar(b, dep[x] + (1<<i));
		int pd = depkpar(d, dep[y] + (1<<i));
		if(dw[pb][i] == dw[pd][i] && dw2[pb][i] == dw2[pd][i])
			ans += 1<<i, x = pb, y = pd;
	}
	
	return ans;
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0);

	pw[0]  = 1; fer(i, 1, maxn) pw[i]  = pw[i-1]  * base;
	pw2[0] = 1; fer(i, 1, maxn) pw2[i] = pw2[i-1] * base % mod;

//	cin >> n;
	n = nextInt();
//	cin >> s;
	scanf("%s", s);

	rep(i, n-1) {
		int u, v;
//		cin >> u >> v; u--, v--;
		u = nextInt(), v = nextInt(), u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	adj[0].pb(n), adj[n].pb(0);
	dfs(n, n, 0);

	cin >> m;
	rep(z, m) {
		int a, b, c, d;
//		cin >> a >> b >> c >> d; a--, b--, c--, d--;
		a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
		a--, b--, c--, d--;
//		cout << solve(a, b, c, d) << '\n';
		writen(solve(a, b, c, d));
	}

	return 0;
}

