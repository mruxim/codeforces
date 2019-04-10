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
typedef pair<ll, ll> pll;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n, m;
pll q[maxn];
pair<pll, int> p[maxn];
pair<ll, int> a[maxn];
set<pair<ll, int>> s;
int ans[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> q[i].X >> q[i].Y;
	rep(i, m) cin >> a[i].X, a[i].Y = i;

	rep(i, n-1) p[i].X.X = q[i+1].X - q[i].Y, p[i].X.Y = q[i+1].Y - q[i].X, p[i].Y = i;

	sort(p, p+n-1);
	sort(a, a+m);

	int pos = m;
	rof(i, n-1, 0) {
		while(pos > 0 && p[i].X.X <= a[pos-1].X) s.insert(a[pos-1]), pos--;
		auto it = s.lower_bound(make_pair(p[i].X.Y + 1, -1));
		if(it == s.begin()) { cout << "No" << endl; return 0; }
		it--;
		ans[p[i].Y] = (*it).Y;
		s.erase(it);
	}

	cout << "Yes" << endl;
	rep(i, n-1) cout << ans[i] + 1 << ' ';
	cout << endl;

	return 0;
}

