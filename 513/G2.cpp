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

const int maxn = 100 + 10;
const int maxk = 200 + 10;

int n, k;
int a[maxn];
double dp[maxn][maxn], odp[maxn][maxn];
double t[maxn][maxn];

inline int bino(int k) { return k * (k+1) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> a[i];

	double tot = bino(n);
	rep(z, k) {
		memcpy(odp, dp, sizeof odp);
		memset(dp, 0, sizeof dp);
		rep(j, n) rep(i, j) {
			double &c = dp[i][j];
			rep(r, n) rep(l, r+1) {
				int ni = i;
				if(l <= i && i <= r) ni = l + r - i;
				int nj = j;
				if(l <= j && j <= r) nj = l + r - j;
				if(ni < nj)
					c += odp[ni][nj] / tot;
				else
					c += (1 - odp[nj][ni]) / tot;
			}
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

