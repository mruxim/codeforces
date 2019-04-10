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

int sod(int x) {
	int r = 0;
	while(x) r += x % 10, x /= 10;
	return r;
}

ll pw(int s, int a) {
	ll r = 1;
	rep(i, a) r *= s;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> v;
	fer(s, 1, 90) {
		ll val = b * pw(s, a) + c;
		if(val < 1e9 && sod(val) == s) v.pb(val);
	}

	cout << sz(v) << endl;
	for(int x: v) cout << x << ' ';
	cout << endl;

	return 0;
}

