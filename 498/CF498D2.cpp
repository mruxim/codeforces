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

const int maxn = 100000 + 1000;
const int lcm = 60;

int n, q;
int a[maxn];
int p[4*maxn][lcm];

void update(int x) {
	rep(m, lcm) {
		int t = p[2*x+1][m];
		p[x][m] = t + p[2*x+2][(t + m) % lcm];
	}
}

void make(int x, int xl, int xr) {
	if(xr - xl == 1) {
		rep(m, lcm) p[x][m] = (m % a[xl] ? 1 : 2);
		return;
	}

	int xm = (xl + xr) / 2;
	make(2*x+1, xl, xm);
	make(2*x+2, xm, xr);

	update(x);
}

void change(int x, int xl, int xr, int qpos) {
	if(qpos < xl || xr <= qpos) return;
	if(xr - xl == 1) {
		rep(m, lcm) p[x][m] = (m % a[xl] ? 1 : 2);
		return;
	}

	int xm = (xl + xr) / 2;
	change(2*x+1, xl, xm, qpos);
	change(2*x+2, xm, xr, qpos);

	update(x);
}

int ask(int x, int xl, int xr, int ql, int qr, int ct = 0) {
	if(qr <= xl || xr <= ql) return ct;
	if(ql <= xl && xr <= qr) {
		ct += p[x][ct % lcm];
		return ct;
	}

	int xm = (xl + xr) / 2;
	ct = ask(2*x+1, xl, xm, ql, qr, ct);
	ct = ask(2*x+2, xm, xr, ql, qr, ct);

	return ct;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	make(0, 0, n);

	cin >> q;
	rep(z, q) {
		char tp; cin >> tp;
		int x, y; cin >> x >> y;
		if(tp == 'A') {
			x--, y--;
			cout << ask(0, 0, n, x, y) << endl;
		} else {
			x--;
			a[x] = y;
			change(0, 0, n, x);
		}
	}

	return 0;
}

