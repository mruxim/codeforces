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

const int maxn = 1000 + 10;

int n, m, k, P;

vector<ll> solve(vector<int> v, int len) {
	multiset<ll> s;
	for(int x: v) s.insert(x);
	vector<ll> ret(k+1, 0);

	ll cur = 0;

	rep(i, k+1) {
		ret[i] = cur;
		ll val = *s.rbegin();
		cur += val;
		s.erase(s.find(val));
		s.insert(val - len * P);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k >> P;

	vector<int> a(n), b(m);
	rep(i, n) rep(j, m) {
		int x; cin >> x;
		a[i] += x; b[j] += x;
	}

	vector<ll> p = solve(a, m);
	vector<ll> q = solve(b, n);

	ll ans = -(1LL << 61);

	rep(i, k+1) {
		ll cur = p[i] + q[k-i];
		cur -= (k-i) * (ll)(i * P);
		smax(ans, cur);
	}
	
	rep(i, k+1) {
		ll cur = q[i] + p[k-i];
		cur -= (k-i) * (ll)(i * P);
		smax(ans, cur);
	}

	cout << ans << endl;

	{ return 0; }
}

