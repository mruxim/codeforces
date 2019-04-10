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

bool check(ll n, ll k, ll d1, ll d2) {
	if(n % 3) return false;
	ll a = 0, b = d1, c = d1+d2;
	ll mn = min(a, min(b, c));
	a -= mn, b -= mn, c -= mn;
	k -= a + b + c;
	if(k < 0 || k % 3) return false;
	ll mx = max(a, max(b, c));
	return n - (3 * mx + k) >= 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	for(cin >> tc; tc--; ) {
		ll n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		
		if(	check(n, k, -d1, -d2) ||
			check(n, k, -d1, d2) ||
			check(n, k, d1, -d2) ||
			check(n, k, d1, d2))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	{ return 0; }
}

