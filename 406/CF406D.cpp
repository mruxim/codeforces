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
ll x[maxn], y[maxn];
int d[maxn], r[maxn];
int par[20][maxn];

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	rof(i, 20, 0) if(d[v] - (1 << i) >= d[u]) v = par[i][v];
	if(u == v) return u;
	rof(i, 20, 0) if(par[i][u] != par[i][v])
		u = par[i][u], v = par[i][v];
	return par[0][u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];

	rof(i, n-1, 0) {
		if(i < n-1) {
			r[i] = i+1;
			while(r[i] != n-1 && (y[r[r[i]]] - y[i]) * (x[r[i]] - x[i]) > (y[r[i]] - y[i]) * (x[r[r[i]]] - x[i]))
				r[i] = r[r[i]];
			d[i] = d[r[i]] + 1;
		}
		else r[i] = i, d[i] = 0;

		par[0][i] = r[i];
		fer(j, 1, 20) par[j][i] = par[j-1][par[j-1][i]];
	}

	int q;
	cin >> q;
	rep(i, q) {
		int u, v; cin >> u >> v; u--, v--;
		cout << lca(u, v) + 1 << ' ';
	}
	cout << endl;

	{ return 0; }
}

