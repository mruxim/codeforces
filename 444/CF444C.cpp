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
ll col[4*maxn];
ll sum[4*maxn], add[4*maxn];

void make(int x, int xl, int xr) {
	if(xr - xl == 1) {
		col[x] = xl + 1;
		return;
	}
	
	int xm = (xl + xr) / 2;
	make(2*x+1, xl, xm);
	make(2*x+2, xm, xr);
}

void shift(int x, int xl, int xr) {
	int xm = (xl + xr) / 2;
	add[2*x+1] += add[x];
	sum[2*x+1] += (xm - xl) * (ll)add[x];
	add[2*x+2] += add[x];
	sum[2*x+2] += (xr - xm) * (ll)add[x];
	add[x] = 0;
	col[2*x+1] = col[2*x+2] = col[x];
}

void modify(int x, int xl, int xr, int ql, int qr, int color) {
	if(qr <= xl || xr <= ql) return;
	if(ql <= xl && xr <= qr && col[x]) {
		int tmp = abs(col[x] - color);
		add[x] += tmp;
		sum[x] += (xr - xl) * (ll)tmp;
		col[x] = color;
		return;
	}

	if(col[x]) shift(x, xl, xr);

	int xm = (xl + xr) / 2;

	modify(2*x+1, xl, xm, ql, qr, color);
	modify(2*x+2, xm, xr, ql, qr, color);

	sum[x] = sum[2*x+1] + sum[2*x+2];
	if(ql <= xl && xr <= qr) col[x] = color;
	else col[x] = 0;
}

ll query(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return 0;
	if(ql <= xl && xr <= qr) return sum[x];

	if(col[x]) shift(x, xl, xr);

	int xm = (xl + xr) / 2;

	return query(2*x+1, xl, xm, ql, qr) + query(2*x+2, xm, xr, ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	make(0, 0, n);

	rep(i, m) {
		int tp; cin >> tp;
		if(tp == 1) {
			int ql, qr, qc; cin >> ql >> qr >> qc; ql--;
			modify(0, 0, n, ql, qr, qc);
		} else {
			int ql, qr; cin >> ql >> qr; ql--;
			cout << query(0, 0, n, ql, qr) << endl;
		}
	}

	{ return 0; }
}

