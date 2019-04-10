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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n, m;
ll a[maxn];
ll v[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> a[i];

	ll ans = 0;
	fer(k, 1, m/n + 1) {
		rep(i, n) v[i] = a[i];
		smin(v[n-1], (m + (m - (k-1) * (ll)n)) * k / 2);
		rof(i, n-1, 0) smin(v[i], v[i+1] - k);
		smax(ans, accumulate(v, v+n, 0LL));
	}

	cout << ans << endl;
	return 0;
}

