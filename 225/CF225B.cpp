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

ll s;
int k;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s >> k;

	v.pb(1);
	while(v.back() < s) {
		ll x = 0;
		rof(i, sz(v), max(0, sz(v) - k))
			x += v[i];
		v.pb(x);
	}

	vector<ll> ans;
	for(int p = sz(v)-1; s; p--)
		while(s >= v[p])
			s -= v[p], ans.pb(v[p]);

	ans.pb(0);
	cout << sz(ans) << endl;
	for(ll x: ans) cout << x << ' ';
	cout << endl;

	return 0;
}

