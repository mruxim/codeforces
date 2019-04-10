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

const int maxn = 1000000 + 100;

int n, m;
int a[maxn];
vector<int> p, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m; smin(m, n);
	rep(i, n) cin >> a[i];
	sort(a, a+n);

	for(int i = 0; i < n; i += m) p.pb(a[i]);
	for(int i = n-1; i >= 0; i -= m) q.pb(a[i]);
	reverse(all(q));

	ll lsum = 0, rsum = 0;
	rep(i, sz(q)) rsum += q[i];

	ll ans = 1e18;

	rep(i, sz(p)) {
		lsum += p[i];

		int pos;

		pos = p[i];
		smin(ans, (i+1)*(ll)pos - lsum + rsum - (sz(p)-i)*(ll)pos);
		pos = q[i];
		smin(ans, (i+1)*(ll)pos - lsum + rsum - (sz(p)-i)*(ll)pos);

		rsum -= q[i];
	}

	cout << ans*2 << endl;

	{ return 0; }
}

