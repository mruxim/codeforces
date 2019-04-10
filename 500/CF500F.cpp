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

const int inf = 1e9;
const int maxn = 4000 + 10;
const int maxb = 4000 + 10;
const int maxq = 20000 + 10;

int n, p, q;
pair<int, pii> g[maxn];
int stime[maxn], cost[maxn], happiness[maxn];
vector<pair<pii, pii>> qs;
int ans[maxq];
int dpl[maxn][maxb], dpr[maxn][maxb];

void solve(vector<pair<pii, pii>> v) {
	if(v.empty()) return;
	int mn = inf, mx = -inf;
	rep(i, sz(v)) smin(mn, v[i].X.X), smax(mx, v[i].X.Y);
	vector<int> ps(mx - mn + 1, 0);
	rep(i, sz(v)) ps[v[i].X.X - mn]++, ps[v[i].X.Y - mn]--;

	int cut = -1, cnt = -1;
	int cur = 0;
	rep(i, sz(ps)) {
		cur += ps[i];
		if(cur > cnt) cnt = cur, cut = i + mn;
	}

	decltype(v) L, R, C;
	rep(i, sz(v))
		if(v[i].X.X <= cut && cut <= v[i].X.Y) C.pb(v[i]);
		else if(v[i].X.Y < cut) L.pb(v[i]);
		else R.pb(v[i]);

	mn = inf, mx = -inf;
	rep(i, sz(C)) smin(mn, C[i].X.X), smax(mx, C[i].X.Y);

	int ls = cut - mn + 1, rs = mx - cut + 1;
	memset(dpl, 0, ls * sizeof(dpl[0]));
	memset(dpr, 0, rs * sizeof(dpr[0]));

	fer(i, 1, ls) {
		int cc = cost[cut - i], hh = happiness[cut - i];
		rep(c, cc) dpl[i][c] = dpl[i-1][c];
		fer(c, cc, maxb) dpl[i][c] = max(dpl[i-1][c], dpl[i-1][c-cc] + hh);
	}
	fer(i, 1, rs) {
		int cc = cost[cut + i - 1], hh = happiness[cut + i - 1];
		rep(c, cc) dpr[i][c] = dpr[i-1][c];
		fer(c, cc, maxb) dpr[i][c] = max(dpr[i-1][c], dpr[i-1][c-cc] + hh);
	}

	for(auto qq: C)
		rep(c, qq.Y.X + 1)
			smax(ans[qq.Y.Y], dpl[cut - qq.X.X][c] + dpr[qq.X.Y - cut][qq.Y.X - c]);

	solve(L);
	solve(R);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> p;
	rep(i, n) cin >> g[i].Y.X >> g[i].Y.Y >> g[i].X;
	sort(g, g+n);
	rep(i, n) stime[i] = g[i].X, cost[i] = g[i].Y.X, happiness[i] = g[i].Y.Y;

	cin >> q;
	rep(i, q) {
		int mtime, budget;
		cin >> mtime >> budget;
		int l = upper_bound(stime, stime+n, mtime-p) - stime;
		int r = upper_bound(stime, stime+n, mtime) - stime;
		qs.pb({{l, r}, {budget, i}});
	}

	solve(qs);

	rep(i, q) cout << ans[i] << endl;

	return 0;
}

