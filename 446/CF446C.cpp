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

const int mod = 1000000000 + 9;
const int maxn = 300000 + 100;

int n, m;
int a[maxn];
int pa[maxn];

int fib[maxn];
int f0[maxn], f1[maxn], sf0[maxn], sf1[maxn];

int s0[4*maxn], s1[4*maxn];
int sum[maxn];

void fix(int &val) {
	while(val >= mod) val -= mod;
	while(val < 0) val += mod;
}

int getkth(int v0, int v1, int k) {
	return (v0 * (ll)f0[k] + v1 * (ll)f1[k]) % mod;
}

int getsum(int v0, int v1, int len) {
	return (sf0[len-1] * (ll)v0 + sf1[len-1] * (ll)v1) % mod;
}

void shift(int x, int xl, int xr) {
	int xm = (xl + xr) / 2;

	s0[2*x+1] += s0[x]; fix(s0[2*x+1]);
	s1[2*x+1] += s1[x]; fix(s1[2*x+1]);
	sum[2*x+1] += getsum(s0[x], s1[x], xm - xl); fix(sum[2*x+1]);

	int v0 = getkth(s0[x], s1[x], xm - xl);
	int v1 = getkth(s0[x], s1[x], xm - xl + 1);
	
	s0[2*x+2] += v0; fix(s0[2*x+2]);
	s1[2*x+2] += v1; fix(s1[2*x+2]);
	sum[2*x+2] += getsum(v0, v1, xr - xm); fix(sum[2*x+2]);

	s0[x] = 0;
	s1[x] = 0;
	sum[x] = sum[2*x+1] + sum[2*x+2]; fix(sum[x]);
}

void add(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return;
	if(ql <= xl && xr <= qr) {
		int id = xl - ql;
		s0[x] += fib[id], s1[x] += fib[id+1];
		fix(s0[x]); fix(s1[x]);
		sum[x] += getsum(fib[id], fib[id+1], xr - xl);
		fix(sum[x]);
		return;
	}

	shift(x, xl, xr);

	int xm = (xl + xr) / 2;
	add(2*x+1, xl, xm, ql, qr);
	add(2*x+2, xm, xr, ql, qr);

	sum[x] = sum[2*x+1] + sum[2*x+2]; fix(sum[x]);
}

int get(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return 0;
	if(ql <= xl && xr <= qr) return sum[x];

	shift(x, xl, xr);

	int xm = (xl + xr) / 2;
	return (get(2*x+1, xl, xm, ql, qr) + get(2*x+2, xm, xr, ql, qr)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
		pa[i+1] = pa[i] + a[i];
		fix(pa[i+1]);
	}

	fib[0] = fib[1] = 1;
	f0[0] = 1, f0[1] = 0;
	f1[0] = 0, f1[1] = 1;
	sf0[0] = 1, sf0[1] = 1;
	sf1[0] = 0, sf1[1] = 1;

	fer(i, 2, maxn) {
		fib[i] = fib[i-1] + fib[i-2]; fix(fib[i]);
		f0[i] = f0[i-1] + f0[i-2]; fix(f0[i]);
		f1[i] = f1[i-1] + f1[i-2]; fix(f1[i]);
		sf0[i] = sf0[i-1] + f0[i]; fix(sf0[i]);
		sf1[i] = sf1[i-1] + f1[i]; fix(sf1[i]);
	}

	while(m--) {
		int tp, l, r;
		cin >> tp >> l >> r; l--;
		if(tp == 1) add(0, 0, n, l, r);
		else cout << (pa[r] - pa[l] + get(0, 0, n, l, r) + (ll)mod) % mod << endl;
	}

	{ return 0; }
}

