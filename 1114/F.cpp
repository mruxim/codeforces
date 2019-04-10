// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;

const int maxn = 400000 + 100;
const int maxa = 300 + 1;
const int pcnt = 62;

int sp[maxa];
vector<int> pr;
int pid[maxa];

int n, q;
int a[maxn];

int xans[4*maxn], xmul[4*maxn];
ll xmask[4*maxn];

void init() {
	iota(sp, sp+maxa, 0);
	for(int i = 2; i * i < maxa; i++)
		for(int j = i * i; j < maxa; j += i)
			if(sp[j] == j)
				sp[j] = i;
	fer(i, 2, maxa)
		if(sp[i] == i)
			pid[i] = sz(pr),
			pr.pb(i);
}

void domul(int &x, int y) {
	x = x * (ll)y % mod;
}

int powmod(int a, int p) {
	int r = 1;
	for(; p; p >>= 1) {
		if(p & 1) domul(r, a);
		domul(a, a);
	}
	return r;
}

ll getmask(int a) {
	ll res = 0;
	while(a > 1)
		res |= 1LL << pid[sp[a]], a /= sp[a];
	return res;
}

void update(int x, int xl, int xr, int qmul) {
	domul(xans[x], powmod(qmul, xr - xl));
	domul(xmul[x], qmul);
}

void push(int x, int xl, int xr) {
	int xm = (xl + xr) / 2;

	update(2*x+1, xl, xm, xmul[x]);
	update(2*x+2, xm, xr, xmul[x]);

	xmul[x] = 1;
}

void pull(int x) {
	xans[x] = mul(xans[2*x+1], xans[2*x+2]);
	xmask[x] = xmask[2*x+1] | xmask[2*x+2];
}

void make(int x, int xl, int xr) {
	xmul[x] = 1;
	if(xr - xl == 1) {
		xans[x] = a[xl];
		xmask[x] = getmask(a[xl]);
		return;
	}
	int xm = (xl + xr) / 2;
	make(2*x+1, xl, xm);
	make(2*x+2, xm, xr);
	pull(x, xl, xr);
}

void modify(int x, int xl, int xr, int ql, int qr, int qmul) {
	if(xr <= ql || qr <= xl) return;
	if(ql <= xl && xr <= qr) {
		update(x, xl, xr, qmul);
		xmask[x] |= getmask(qmul);
		return;
	}
	
	int xm = (xl + xr) / 2;
	push(x, xl, xr);
	modify(2*x+1, xl, xm, ql, qr, qmul);
	modify(2*x+2, xm, xr, ql, qr, qmul);
	pull(x, xl, xr);
}

pair<int, ll> getans(int x, int xl, int xr, int ql, int qr) {
	if(xr <= ql || qr <= xl) return 0;
	if(ql <= xl && xr <= qr)
		return {xmul[x], xmask[x]};
	
	int xm = (xl + xr) / 2;
	push(x, xl, xr);
	auto res1 = getans(2*x+1, xl, xm, ql, qr);
	auto res2 = getans(2*x+2, xm, xr, ql, qr);
	pull(x, xl, xr);
	return {res1.X * (ll)res2.X % mod, res1.Y | res2.Y};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	init();

	cin >> n >> q;
	rep(i, n) cin >> a[i];

	make(0, 0, n);

	rep(z, q) {
		char com[11];
		int l, r;
		cin >> com >> l >> r;
		l--;
		if(com[0] == 'M') {
			int x;
			cin >> x;
			while(x > 1) {
				int p = sp[x];
				int cnt = 0;
				while(x % p == 0) x /= p, cnt++;
				s[pid[p]].update(0, 0, n, l, r, cnt);
			}
		} else {
			int ans = 1;
			rep(i, sz(pr)) {
				int pw = s[i].getsum(0, 0, n, l, r);
				if(pw == 0) continue;
				ans = ans * (ll)powmod(pr[i], pw-1) % mod;
				ans = ans * (ll)(pr[i] - 1) % mod;
			}
			cout << ans << endl;
		}
	}

	return 0;
}

