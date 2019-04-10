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

const int mod = 1000000000 + 7;
const int base = 727;
const int maxn = 100000 + 100;

int n, q, q2;
string str;
int hpow[maxn], spow[maxn];

int h[4*maxn], sv[4*maxn];

void update(int x, int xl, int xr, int dig) {
	if(dig == 0) return;
	sv[x] = dig;
	h[x] = spow[xr - xl] * (ll)dig % mod;
}

void push(int x, int xl, int xr) {
	int xm = (xl + xr) / 2;
	update(2*x+1, xl, xm, sv[x]);
	update(2*x+2, xm, xr, sv[x]);
	sv[x] = 0;
}

void pull(int x, int xl, int xr) {
	int xm = (xl + xr) / 2;
	h[x] = (h[2*x+1] * (ll)hpow[xr - xm] + h[2*x+2]) % mod;
}

void change(int x, int xl, int xr, int ql, int qr, int qd) {
	if(qr <= xl || xr <= ql) return;
	if(ql <= xl && xr <= qr) {
		update(x, xl, xr, qd);
		return;
	}

	int xm = (xl + xr) / 2;

	push(x, xl, xr);

	change(2*x+1, xl, xm, ql, qr, qd);
	change(2*x+2, xm, xr, ql, qr, qd);

	pull(x, xl, xr);
}

int gethash(int x, int xl, int xr, int ql, int qr) {
	if(qr <= xl || xr <= ql) return 0;
	if(ql <= xl && xr <= qr) {
		return h[x] * (ll)hpow[qr - xr] % mod;
	}

	int xm = (xl + xr) / 2;

	push(x, xl, xr);

	int res = 0;
	res += gethash(2*x+1, xl, xm, ql, qr);
	res += gethash(2*x+2, xm, xr, ql, qr);
	if(res >= mod) res -= mod;

	pull(x, xl, xr);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	hpow[0] = 1;
	fer(i, 1, maxn) {
		hpow[i] = hpow[i-1] * (ll)base % mod;
		spow[i] = (spow[i-1] + hpow[i-1]) % mod;
	}

	cin >> n >> q >> q2; q += q2;
	cin >> str;
	rep(i, n) change(0, 0, n, i, i+1, (int)str[i]);


	while(q--) {
		int tp, l, r, d;
		cin >> tp >> l >> r >> d; l--;
		if(tp == 1) {
			change(0, 0, n, l, r, d + '0');
		} else {
			int hash1 = gethash(0, 0, n, l, r-d);
			int hash2 = gethash(0, 0, n, l+d, r);
			cout << (hash1 == hash2 ? "YES" : "NO") << endl;
		}
	}

	return 0;
}

