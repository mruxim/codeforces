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

const int maxnm = 1000000 + 100;

long double lg[maxnm];

long double C(int n, int k) {
	if(k < 0 || k > n) return lg[0];
	long double res = 0;
	rof(i, n+1, n-k+1)
		res = res + lg[i] - lg[n+1-i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, maxnm) lg[i] = log(i);

	int n, m;
	cin >> n >> m;

	long double sum = 0;
	long double ans = 0;
	fer(i, 1, n+1) {
		long double prob = C(m, i) + C(m*n-m, n-i) - C(m*n, n);
		prob += lg[i];
		ans += exp(prob + lg[i] - lg[n]);
		sum += exp(prob);
	}
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << ans / sum << endl;

	{ return 0; }
}

