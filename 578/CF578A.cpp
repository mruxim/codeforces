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

const double inf = 1e18;

double a, b;

double solve(double p, int r) {
	if(p < 0) return inf;
	int v = p / b;
	if(v % 2) v--;
	if(v < r) v = r;
	if(p / v < b) return inf;
	return p / v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> a >> b;

	double ans;
	if(a == b) ans = a;
	else ans = min(solve(a - b, 0), solve(a + b, 2));

	if(ans >= inf / 2)
		cout << -1 << endl;
	else {
		cout.setf(ios::fixed);
		cout.precision(12);
		cout << ans << endl;
	}

	return 0;
}

