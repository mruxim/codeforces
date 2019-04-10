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

const int maxn = 200000 + 100;

int n;
int d[maxn];
ll A, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> A;
	rep(i, n) cin >> d[i], s += d[i];

	rep(i, n) {
		ll lf = max(1ll, A - (s - d[i]));
		ll rg = min((ll)d[i], A - (n-1));
		cout << d[i] - (rg - lf + 1) << ' ';
	}
	cout << endl;


	return 0;
}

