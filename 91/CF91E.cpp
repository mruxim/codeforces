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
#define rall(X) (X).rbegin(),(X).rend()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, q;
int a[maxn], b[maxn];
int l[maxn], r[maxn], t[maxn], id[maxn], ans[maxn];
vector<int> v[4*maxn];
int curt;

inline ll f(int i) { return a[i] + b[i] * (ll)curt; }

inline int pass(int i, int j) { // assumed: a[i] > a[j] && b[i] < b[j]
	return (a[i] - a[j] + (b[j] - b[i] - 1)) / (b[j] - b[i]);
}

void build(int x, int xl, int xr) {
	if(xr - xl == 1) {
		v[x].pb(xl);
		return;
	}

	int xm = (xl + xr) / 2;
	build(2*x+1, xl, xm);
	build(2*x+2, xm, xr);

	merge(rall(v[2*x+1]), rall(v[2*x+2]), back_inserter(v[x]), [](int i, int j)
			{ return a[i] != a[j] ? a[i] > a[j] : b[i] > b[j]; } );

	int pos = 0;
	for(int i: v[x]) {
		if(pos >= 1 && b[v[x][pos-1]] >= b[i]) continue;
		while(pos >= 2 && pass(v[x][pos-1], i) <= pass(v[x][pos-2], v[x][pos-1])) pos--;
		v[x][pos++] = i;
	}

	v[x].erase(v[x].begin() + pos, v[x].end());
	reverse(all(v[x]));
}

int query(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return -1;
	if(ql <= xl && xr <= qr) {
		while(sz(v[x]) >= 2 && f(v[x].back()) <= f(v[x][sz(v[x])-2])) v[x].pop_back();
		return v[x].back();
	}

	int xm = (xl + xr) / 2;
	int ret1 = query(2*x+1, xl, xm, ql, qr);
	int ret2 = query(2*x+2, xm, xr, ql, qr);
	if(ret1 == -1) return ret2;
	if(ret2 == -1) return ret1;
	return f(ret1) > f(ret2) ? ret1 : ret2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, q) cin >> l[i] >> r[i] >> t[i], l[i]--;

	iota(id, id+q, 0);
	sort(id, id+q, [](int i, int j) { return t[i] < t[j]; } );

	build(0, 0, n);

	rep(i, q) {
		curt = t[id[i]];
		ans[id[i]] = query(0, 0, n, l[id[i]], r[id[i]]);
	}

	rep(i, q) cout << ans[i] + 1 << endl;

	{ return 0; }
}

