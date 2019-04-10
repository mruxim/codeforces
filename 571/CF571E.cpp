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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const vector<pii> nll = vector<pii>(1, pii(-1, -1));
const int maxn = 100 + 10;

int n;
vector<pii> a[maxn], b[maxn];

vector<pii> factor(int x) {
	vector<pii> v;
	for(int p = 2; p*p <= x; p++) if(x % p == 0) {
		v.pb(pii(p, 0));
		while(x % p == 0) x /= p, v.back().Y++;
	}
	if(x > 1) v.pb(pii(x, 1));
	return v;
}

vector<pii> dv(vector<pii> a, vector<pii> b) {
	int pos = 0;
	rep(i, sz(b)) {
		while(pos < sz(a) && a[pos].X != b[i].X) pos++;
		if(pos == sz(a)) return nll;
		a[pos].Y -= b[pos].Y;
		if(a[pos].Y < 0) return nll;
	}
	vector<pii> c;
	for(pii p: a) if(p.Y) c.pb(p);
	return c;
}

vector<pii> mul(vector<pii> a, vector<pii> b) {
	int p = 0, q = 0;
	vector<pii> r;
	while(p < sz(a) || q < sz(b)) {
		if(p < sz(a) && q < sz(b) && a[p].X == b[q].X)
			r.pb(pii(a[p].X, a[p].Y + b[q].Y)), p++, q++;
		else if(p == sz(a) || a[p].X > b[q].X)
			r.pb(pii(b[q].X, b[q].Y)), q++;
		else
			r.pb(pii(a[p].X, a[p].Y)), p++;
	}
	return r;
}

int mpow(int a, int b) {
	int r = 1;
	for( ; b; b >>= 1) {
		if(b & 1) r = r * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return r;
}

pii eqt(int x, int xm, int y, int ym) {
}

int calc(vector<pii> v) {
	int r = 1;
	for(pii p: v) r = r * (ll)mpow(p.X, p.Y) % mod;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int ta, tb;
		cin >> ta >> tb;
		a[i] = factor(ta);
		b[i] = factor(tb);
	}

	rep(i, n) {
		bool ok = true;
		rep(j, n) {
			vector<pii> d = dv(a[i], a[j]);
			if(d == nll) { ok = false; break; }
		}
		if(ok) { cout << calc(a[i]) << endl; return 0; }
	}

	rep(i, n) {
		a[i] = mul(a[i], b[i]);
		vector<pii> c(sz(a[i]));
		int p = 0;
		rep(j, sz(c)) {
			c[j].X = a[i][j].X;
			if(p < sz(b[i]) && b[i][p].X < c[j].X) p++;
			if(p < sz(b[i]) && b[i][p].X == c[j].X) c[j].Y = b[i][p].Y;
		}
		b[i] = c;
	}

	rep(i, n) {
		if(sz(a[i]) != sz(a[0])) { cout << -1 << endl; return 0; }
		rep(j, sz(a[i])) if(a[i][j].X != a[0][j].X) { cout << -1 << endl; return 0; }
	}

	int k = sz(a[0]);
	int step = 0;
	rep(i, n) rep(j, n) rep(l, k) if(b[i][l].Y == 0 && b[j][l].Y) {
		if(a[i][l].Y < a[j][l].Y || (a[i][l].Y - a[j][l].Y) % b[j][l].Y) { cout << -1 << endl; return 0; }
		int tmp = (a[i][l].Y - a[j][l].Y) / b[j][l].Y;
		if(step != 0 && step != tmp) { cout << -1 << endl; return 0; }
		step = tmp;
	}

	if(step) {
		rep(j, k) a[0][j].Y += b[0][j].Y * step;
		rep(i, n) rep(j, k) if(a[0][j].Y != a[i][j].Y + b[i][j].Y * step) { cout << -1 << endl; return 0; }
		cout << calc(a[0]) << endl;
		return 0;
	}
	
	rep(i, n) rep(l, k) if(b[0][l].Y) {
		
	}



	return 0;
}

