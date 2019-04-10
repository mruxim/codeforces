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

const ll lim = 10000000LL*10000000;

ll n, k;
ll du[10][

void check(ll v) {
	if(v < 100) { k--; return; }
	int pr = v % 10; v /= 10;
	int cr = v % 10; v /= 10;
	while(v) {
		int nr = v % 10; v /= 10;
		if((nr - cr) * (cr - pr) >= 0) return;
		pr = cr, cr = nr;
	}
	k--; return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	if(n * k > lim) { cout << -1 << endl; return 0; }

	if(n > 1e7) {
		ll cur = n;
		for(check(cur); k && cur <= lim; check(cur += n));
		cout << (cur < lim ? cur : -1) << endl;
	} else {
	}

	return 0;
}

