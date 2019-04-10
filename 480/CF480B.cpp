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

const int maxn = 100000 + 100;

int n, l, x, y;
int a[maxn];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> l >> x >> y;
	rep(i, n) cin >> a[i], s.insert(a[i]);

	bool hx = false, hy = false;
	rep(i, n) {
		if(s.find(a[i] - x) != s.end()) hx = true;
		if(s.find(a[i] - y) != s.end()) hy = true;
	}

	if(hx && hy) { cout << 0 << endl; return 0; }
	if(hx || hy) {
		int v = x;
		if(hx) v = y;
		cout << 1 << endl;
		cout << v << endl;
		return 0;
	}

	rep(i, n) {
		if(s.find(a[i] - x - y) != s.end()) {
			cout << 1 << endl;
			cout << a[i] - x << endl;
			return 0;
		}
		if(s.find(a[i] - y + x) != s.end() && a[i] + x < l) {
			cout << 1 << endl;
			cout << a[i] + x << endl;
			return 0;
		}
		if(s.find(a[i] + y - x) != s.end() && a[i] - x > 0) {
			cout << 1 << endl;
			cout << a[i] - x << endl;
			return 0;
		}
	}

	cout << 2 << endl;
	cout << x << ' ' << y << endl;

	return 0;
}

