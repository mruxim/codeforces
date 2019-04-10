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
int a[maxn];
int mx[4*maxn];
ll sum[4*maxn];

void modify(int x, int xl, int xr, int ql, int qr, int val, int type) {
	if(qr <= xl || xr <= ql) return;
	if(type == 2 && mx[x] < val) return;
	
	if(xr - xl == 1) {
		a[xl] = (type == 2 ? a[xl] % val : val);
		mx[x] = sum[x] = a[xl];
		return;
	}

	int xm = (xl + xr) / 2;
	modify(2*x+1, xl, xm, ql, qr, val, type);
	modify(2*x+2, xm, xr, ql, qr, val, type);

	mx[x] = max(mx[2*x+1], mx[2*x+2]);
	sum[x] = sum[2*x+1] + sum[2*x+2];
}

ll getsum(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return 0;
	if(ql <= xl && xr <= qr) return sum[x];

	int xm = (xl + xr) / 2;
	return getsum(2*x+1, xl, xm, ql, qr) + getsum(2*x+2, xm, xr, ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
		modify(0, 0, n, i, i+1, a[i], 3);
	}

	while(m--) {
		int type; cin >> type;
		if(type == 1) {
			int l, r; cin >> l >> r; l--;
			cout << getsum(0, 0, n, l, r) << endl;
		} else if(type == 2) {
			int l, r, val; cin >> l >> r >> val; l--;
			modify(0, 0, n, l, r, val, type);
		} else {
			int k, val; cin >> k >> val; k--;
			modify(0, 0, n, k, k+1, val, type);
		}
	}

	{ return 0; }
}

