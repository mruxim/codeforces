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

const int inf = 1000000000 + 10;
const int maxn = 100000 + 100;

int n, l, r;
int a[maxn], p[maxn];
int rv[maxn], c[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> l >> r;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> p[i], p[i]--, rv[p[i]] = i;

	int cur = -inf;
	rep(i, n) {
		c[rv[i]] = cur = max(cur + 1, l - a[rv[i]]);
		if(c[rv[i]] + a[rv[i]] > r) {
			cout << -1 << endl;
			return 0;
		}
	}

	rep(i, n) cout << (i ? " " : "") << a[i] + c[i];
	cout << endl;

	return 0;
}

