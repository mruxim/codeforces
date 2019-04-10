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

const int mod = 1000000000+7;

int a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> a >> b;

	ll ans = 0;

	fer(r, 1, b) {
//		r -> (a+1)*r-1
		ans += a * (ll)r % mod;
		ll tmp = ((a+1)*(ll)r) % mod * a % mod;
		if(tmp % 2 == 0) tmp /= 2;
		else tmp += mod, tmp /= 2;
		ans = (ans + tmp * b) % mod;
	}

	cout << ans << endl;

	return 0;
}

