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

const int maxn = 1000 + 10;

int n, m;
int a[maxn][maxn];
int ul[maxn][maxn], ur[maxn][maxn];
int dl[maxn][maxn], dr[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];

	rep(i, n) rep(j, m) {
		if(i) smax(ul[i][j], ul[i-1][j]);
		if(j) smax(ul[i][j], ul[i][j-1]);
		ul[i][j] += a[i][j];
	}
	rof(i, n, 0) rep(j, m) {
		if(i+1<n) smax(dl[i][j], dl[i+1][j]);
		if(j) smax(dl[i][j], dl[i][j-1]);
		dl[i][j] += a[i][j];
	}
	rep(i, n) rof(j, m, 0) {
		if(i) smax(ur[i][j], ur[i-1][j]);
		if(j+1<m) smax(ur[i][j], ur[i][j+1]);
		ur[i][j] += a[i][j];
	}
	rof(i, n, 0) rof(j, m, 0) {
		if(i+1<n) smax(dr[i][j], dr[i-1][j]);
		if(j+1<m) smax(dr[i][j], dr[i][j+1]);
		dr[i][j] += a[i][j];
	}

	int ans = 0;
	fer(i, 1, n-1) fer(j, 1, m-1)
		smax(ans, ul[i-1][j] + dr[i+1][j] + ur[i][j+1] + dl[i][j-1]),
		smax(ans, ul[i][j-1] + dr[i][j+1] + ur[i-1][j] + dl[i+1][j]);

	cout << ans << endl;

	{ return 0; }
}

