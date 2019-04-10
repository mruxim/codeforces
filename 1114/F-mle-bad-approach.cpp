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

void addto(int &x, ll y) {
	if(y == 0) return;
	x = (x + y) % (mod-1);
	if(x == 0) x = mod-1;
}

struct ST {
	int prime;
	int sum[4*maxn], add[4*maxn];
	
	void push(int x, int xl, int xr) {
		int xm = (xl + xr) / 2;

		add[2*x+1] += add[x];
		addto(sum[2*x+1], add[x] * (ll)(xm - xl));
		
		add[2*x+2] += add[x];
		addto(sum[2*x+2], add[x] * (ll)(xr - xm));
		
		add[x] = 0;
	}

	void pull(int x, int xl, int xr) {
		xl = xl; xr = xr;
		sum[x] = sum[2*x+1] + sum[2*x+2];
		if(sum[x] >= mod) sum[x] -= mod-1;
	}

	void make(int x, int xl, int xr) {
		if(xr - xl == 1) {
			while(a[xl] % prime == 0)
				a[xl] /= prime, sum[x]++;
			return;
		}

		int xm = (xl + xr) / 2;
		make(2*x+1, xl, xm);
		make(2*x+2, xm, xr);
		pull(x, xl, xr);
	}

	void update(int x, int xl, int xr, int ql, int qr, int qadd) {
		if(xr <= ql || qr <= xl) return;
		if(ql <= xl && xr <= qr) {
			add[x] += qadd;
			addto(sum[x], qadd * (ll)(xr - xl));
			return;
		}
		
		int xm = (xl + xr) / 2;
		push(x, xl, xr);
		update(2*x+1, xl, xm, ql, qr, qadd);
		update(2*x+2, xm, xr, ql, qr, qadd);
		pull(x, xl, xr);
	}

	int getsum(int x, int xl, int xr, int ql, int qr) {
		if(xr <= ql || qr <= xl) return 0;
		if(ql <= xl && xr <= qr)
			return sum[x];
		
		int xm = (xl + xr) / 2;
		push(x, xl, xr);
		int res = 0;
		res += getsum(2*x+1, xl, xm, ql, qr);
		res += getsum(2*x+2, xm, xr, ql, qr);
		if(res >= mod) res -= mod-1;
		pull(x, xl, xr);
		return res;
	}
} s[pcnt];

int powmod(int a, int p) {
	int r = 1;
	for(; p; p >>= 1) {
		if(p & 1)
			r = r * (ll)a % mod;
		a = a * (ll)a % mod;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	init();

	cin >> n >> q;
	rep(i, n) cin >> a[i];

	rep(i, sz(pr)) {
		s[i].prime = pr[i];
		s[i].make(0, 0, n);
	}

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

