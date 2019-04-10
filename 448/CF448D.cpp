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

const int maxn = 500000 + 100;

int n, m;
ll k;

ll cnt(ll val) {
	ll ret = 0;
	fer(i, 1, n+1)
		ret += min((ll)m, val / i);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;

	ll lo = 0, hi = maxn*(ll)maxn;
	while(hi - lo > 1) {
		ll md = (lo + hi) / 2;
		if(cnt(md) < k)
			lo = md;
		else
			hi = md;
	}

	cout << hi << endl;

	{ return 0; }
}

