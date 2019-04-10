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

int n, d;
ll x;
int a[maxn], b[maxn];
int c[maxn];

struct cmp {
	bool operator()(int x, int y) {
		return a[x] != a[y] ? a[x] > a[y] : x < y;
	}
};

set<int, cmp> s;


ll nx() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> d >> x;

	iota(a, a+n, 1);
	rep(i, n) swap(a[i], a[nx() % (i+1)]);

	rep(i, n) b[i] = (i < d ? 1 : 0);
	rep(i, n) swap(b[i], b[nx() % (i+1)]);

	if(d <= 600) {
		rep(i, n) if(b[i])
			fer(j, i, n) c[j] = max(c[j], a[j-i]);
	} else {
		rep(i, n) {
			s.insert(i);
			for(int x: s) if(b[i-x]) {
				c[i] = a[x]; break;
			}
		}
	}

	rep(i, n) cout << c[i] << endl;

	{ return 0; }
}

