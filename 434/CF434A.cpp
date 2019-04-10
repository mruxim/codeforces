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

const int maxn = 100000 + 100;

int n, m;
int a[maxn];
vector<int> v[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) cin >> a[i], a[i]--, v[a[i]].pb(i);

	ll ans = 0;
	rep(i, m-1) ans += abs(a[i] - a[i+1]);

	ll old = ans;

	if(ans == 0) {
		cout << 0 << endl;
		return 0;
	}



	rep(i, n) {
		vector<int> t;
		ll cur = 0;
		for(int x: v[i]) {
			if(x && a[x-1] != i) t.pb(a[x-1]), cur += abs(i - a[x-1]);
			if(x+1 < m && a[x+1] != i) t.pb(a[x+1]), cur += abs(i - a[x+1]);
		}
		sort(all(t));
		int nval = t[sz(t)/2];
		ll ncur = 0;
		for(int x: v[i]) {
			if(x && a[x-1] != i) t.pb(a[x-1]), ncur += abs(nval - a[x-1]);
			if(x+1 < m && a[x+1] != i) t.pb(a[x+1]), ncur += abs(nval - a[x+1]);
		}
		smin(ans, old - (cur - ncur));
	}

	cout << ans << endl;

	{ return 0; }
}

