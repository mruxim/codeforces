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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = 1e9 + 100;
const int maxn = 100000 + 100;

int n, m;
int L[maxn], R[maxn];
vector<int> adj[maxn];
int c[maxn];
vector<pair<pii, pii>> v, r;

bool can;
pii p[2];

void dfs(int u, int col) {
	if(c[i] != -1) { can &= (c[u] == col); return; }
	smax(p[col].X, L[u]);
	smin(p[col].X, R[u]);
	c[u] = col;
	for(int v: adj[u]) dfs(v, col ^ 1);
}

int al, ar, bl, br;
int a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t >> T;
	cin >> n >> m;
	rep(i, n) cin >> L[i] >> R[i];
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	al = bl = -inf;
	ar = br = inf;

	memset(c, -1, sizeof c);
	rep(i, n) if(c[i] == -1) {
		can = true;
		rep(z, 2) p[z].X = -inf, p[z].Y = inf;
		dfs(i, 0);

		if(p[0].X > p[1].X || (p[0].X == p[1].X && p[0].Y < p[1].Y))
			swap(p[0], p[1]);
		if(p[0].Y <= p[1].Y) {
			smax(al, p[0].X);
			smin(ar, p[0].Y);
			smax(bl, p[1].X);
			smin(br, p[1].Y);
		} else
			v.pb({p[0], p[1]});
	}

	cout << "POSSIBLE" << endl;
	cout << a << ' ' << b << endl;
	rep(i, n) cout << (L[i] <= a && a <= R[i] ? 1 : 2);
	cout << endl;

	return 0;
}

