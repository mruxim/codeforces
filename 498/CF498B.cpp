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

const int maxn = 5000 + 100;
const int maxT = 5000 + 100;

int n, T;
double dp[maxn][maxT];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> T;
	
	dp[0][0] = 1;
	rep(z, n) {
		double p; int t;
		cin >> p >> t;
		p /= 100;

		double cur = 0, pw = pow(1 - p, t - 1);
		rep(i, T+1) {
			if(i >= t)
				cur -= dp[z][i - t] * pw,
				dp[z+1][i] = dp[z][i - t] * pw;
			dp[z+1][i] += cur * p;
			cur *= 1 - p;
			cur += dp[z][i];
		}
	}

	double ans = 0;
	fer(i, 1, n+1) rep(j, T+1) ans += dp[i][j];

	cout.setf(ios::fixed);
	cout.precision(9);
	cout << ans << endl;

	return 0;
}

