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

#define ws WS

const int maxn = 3000 + 100;

int n;
vector<pii> adj[maxn];
int cnt[maxn];
int ws[maxn];
int st[maxn], tp;
vector<pii> v;

void dfs(int u, int th, int par = -1, int pare = 1e9) {
	st[tp++] = u;
	for(pii vw: adj[u]) {
		int v = vw.X, w = vw.Y;
		if(v == par) continue;
		dfs(v, th, u, w);
	}
	if(pare >= th) {
		int ct = 0, sum = 0;
		do {
			tp--;
			ct++, sum += cnt[st[tp]];
		} while(st[tp] != u);
		v.pb({ct, sum});
	}
}

bool check(int th) {
	v.clear();
	dfs(0, th);
	sort(all(v), greater<pii>());
	int r = 0;
	fer(i, 1, sz(v)) r += v[i].Y;
	return v[0].X <= r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		ws[i] = w;
	}
	rep(i, n) cin >> cnt[i];

	sort(ws, ws+n-1);
	int wc = unique(ws, ws+n-1) - ws;

	int lo = 0, hi = wc;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		if(check(ws[md])) lo = md;
		else hi = md;
	}

	cout << ws[lo] << endl;

	{ return 0; }
}

