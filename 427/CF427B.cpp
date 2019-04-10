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

int n, t, c;
vector<int> v(1, 0);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> t >> c;

	rep(i, n) {
		int x; cin >> x;
		if(x <= t) v.back()++;
		else v.pb(0);
	}

	int ans = 0;
	for(int len: v) ans += max(0, len - c + 1);

	cout << ans << endl;

	{ return 0; }
}

