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

const int maxn = 100 + 2;

int n, k;
int a[maxn];
double dp[maxn][maxn], odp[maxn][maxn];
double t[maxn][maxn];

inline int bino(int k) { return k * (k+1) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> a[i];

	smin(k, 1000);

	double tot = bino(n);
	rep(z, k) {
		memcpy(odp, dp, sizeof odp);
		rep(j, n) rep(i, j) {
			double &c = dp[i][j];
			c = (bino(i) + bino(j-i-1) + bino(n-j-1)) * odp[i][j];

			rep(k, n-(j-i)) {
				int L = (k < i ? k : i) + 1;
				int R = n - (j > k + j - i ? j : k + j - i);
				c += (L < R ? L : R) * (1 - odp[k][k+(j-i)]);
			}

			rep(k, i) c += (k+1 < j-i ? k+1 : j-i) * odp[k][j];
			fer(k, i, j) c += (i+1 < j-k ? i+1 : j-k) * odp[k][j];

			fer(k, i+1, j) c += (k-i < n-j ? k-i : n-j) * odp[i][k];
			fer(k, j, n) c += (j-i < n-k ? j-i : n-k) * odp[i][k];

			c /= tot;
		}
	}

	double ans = 0;
	rep(j, n) rep(i, j)
		ans += dp[i][j] * (a[i] < a[j]) + (1 - dp[i][j]) * (a[i] > a[j]);

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << ans << endl;

	return 0;
}

