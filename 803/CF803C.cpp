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

ll n, k;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	if(k > 10000000) { cout << -1 << endl; return 0; }

	for(ll i = 1; i * i <= n; i++) if(n % i == 0) {
		v.pb(i);
		if(i * i != n) v.pb(n / i);
	}

	sort(all(v));
	ll s = k * (k+1) / 2;

	int lo = -1, hi = sz(v);
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		ll g = v[md];

		if(g * s <= n) lo = md;
		else hi = md;
	}

	if(lo == -1) cout << -1 << endl;
	else {
		ll c = 0;
		rep(i, k) {
			int x = v[lo] * (i+1);
			if(i < k-1) cout << (i ? " " : "") << x;
			else cout << (i ? " " : "") << n - c << endl;
			c += x;
		}
	}

	return 0;
}

