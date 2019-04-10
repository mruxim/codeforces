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
int b[maxn];

ll func(int th) {
	ll ret = 0;
	rep(i, n) ret += max(0, th - a[i]);
	rep(i, m) ret += max(0, b[i] - th);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];

	int lo = 0, hi = 1e9;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		if(func(md) < func(md+1))
			hi = md;
		else
			lo = md;
	}

	cout << func(hi) << endl;

	{ return 0; }
}

