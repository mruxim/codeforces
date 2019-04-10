// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = int(1e9) + 100;
const int maxn = 100000 + 100;

int n, k;
int b[maxn];
int qt[maxn], ql[maxn], qr[maxn], qx[maxn];
int store[2*maxn], len;

int p[20][maxn];

int lazy[4*maxn], mn[4*maxn];

void update(int x, int val) {
	mn[x] = lazy[x] = val;
}

void sset(int x, int xl, int xr, int ql, int qr, int qval) {
	if(xr <= ql || qr <= xl) return;
	if(ql <= xl && xr <= qr) {
		update(x, qval);
		return;
	}

	int xm = (xl + xr) / 2;

	if(lazy[x] != 0) update(2*x+1, lazy[x]), update(2*x+2, lazy[x]); lazy[x] = 0;

	sset(2*x+1, xl, xm, ql, qr, qval);
	sset(2*x+2, xm, xr, ql, qr, qval);

	mn[x] = min(mn[2*x+1], mn[2*x+2]);
}

int ask(int x, int xl, int xr, int ql, int qr) {
	if(xr <= ql || qr <= xl) return inf;
	if(ql <= xl && xr <= qr) return mn[x];

	int xm = (xl + xr) / 2;
	if(lazy[x] != 0) update(2*x+1, lazy[x]), update(2*x+2, lazy[x]); lazy[x] = 0;
	int ret = inf;
	smin(ret, ask(2*x+1, xl, xm, ql, qr));
	smin(ret, ask(2*x+2, xm, xr, ql, qr));

	mn[x] = min(mn[2*x+1], mn[2*x+2]);
	return ret;
}

int getmin(int l, int r) {
	if(l == r) return inf;
	int k = 0;
	while((1 << k) <= (r - l)) k++; k--;
	return min(p[k][l], p[k][r - (1<<k)]);
}

int q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> b[i];

	cin >> q;
	rep(i, q) {
		cin >> qt[i] >> ql[i] >> qr[i];
		if(qt[i] == 1) cin >> qx[i];
		ql[i]--;
		store[len++] = ql[i], store[len++] = qr[i];
	}

	store[len++] = n * k;
	sort(store, store + len);
	len = unique(store, store + len) - store;

	rep(k, 20) rep(i, n) {
		if(k == 0) p[k][i] = b[i];
		else p[k][i] = min(p[k-1][i], p[k-1][min(i + (1<<(k-1)), n-1)]);
	}

	rep(i, len-1) {
		int lf = store[i], rg = store[i+1];
		int val = inf;
		if(lf / n == rg / n)
			val = getmin(lf % n, rg % n);
		else if(lf / n + 1 == rg / n)
			val = min(getmin(lf % n, n), getmin(0, rg % n));
		else
			val = getmin(0, n);

		cerr << " !! " << lf << ' ' << rg << ' ' << val << endl;
		sset(0, 0, len-1, i, i+1, val);
	}

	rep(i, q) {
		ql[i] = lower_bound(store, store + len, ql[i]) - store;
		qr[i] = lower_bound(store, store + len, qr[i]) - store;
		if(qt[i] == 2)
			cout << ask(0, 0, len-1, ql[i], qr[i]) << endl;
		else
			sset(0, 0, len-1, ql[i], qr[i], qx[i]);
	}

	return 0;
}

