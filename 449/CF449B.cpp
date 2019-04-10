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

const ll inf = 1LL << 61;

const int maxn = 100000 + 100;
const int maxm = 300000 + 100000 + 100;

int n, m, k;
int ec;
int hed[maxn];
int to[2*maxm], wei[2*maxm], prv[2*maxm], tp[2*maxm];
int keep;

ll dis[maxn];
int par[maxn];

struct cmp {
	bool operator()(int x, int y) {
		if(dis[x] != dis[y]) return dis[x] < dis[y];
		return x < y;
	}
};

set<int, cmp> s;

void add_edge(int u, int v, int w, int t) {
	to[ec] = v, wei[ec] = w, tp[ec] = t, prv[ec] = hed[u], hed[u] = ec++;
	to[ec] = u, wei[ec] = w, tp[ec] = t, prv[ec] = hed[v], hed[v] = ec++;
}

void dij() {
	fill(dis, dis+n, inf);
	fill(par, par+n, -1);

	dis[0] = 0;
	s.insert(0);

	while(!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());

		for(int e = hed[u]; e != -1; e = prv[e]) {
			int v = to[e], w = wei[e];
			if(dis[v] < dis[u] + w) continue;
			if(dis[v] == dis[u] + w && tp[par[v]] == 0) continue;
			s.erase(v);
			dis[v] = dis[u] + w;
			par[v] = e;
			s.insert(v);
		}
	}

	fer(i, 1, n) if(par[i] != -1 && tp[par[i]] == 1) keep++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	
	fill(hed, hed+n, -1);

	rep(i, m) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		add_edge(u, v, w, 0);
	}
	rep(i, k) {
		int u, w; cin >> u >> w; u--;
		add_edge(0, u, w, 1);
	}

	dij();

	cout << k - keep << endl;

	{ return 0; }
}

