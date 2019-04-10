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

const int maxn = 200 + 10;
const int inf = 1<<28;

int n, m, k;
int a[maxn];
int d[maxn][maxn];
int pos[7];
int dp[1<<7][maxn];
string mat[maxn];

void solve(int mask, int id) {
	int goal = dp[mask][id];
	mat[id/m][id%m] = 'X';
	if(a[id] == goal) return;

	if(id % m && goal == dp[mask][id-1] + a[id]) { solve(mask, id-1); return; }
	if(id % m + 1 < m && goal == dp[mask][id+1] + a[id]) { solve(mask, id+1); return; }
	if(id - m >= 0 && goal == dp[mask][id-m] + a[id]) { solve(mask, id-m); return; }
	if(id + m < n && goal == dp[mask][id+m] + a[id]) { solve(mask, id+m); return; }

	for(int sub = (mask-1) & mask; sub; sub = (sub-1) & mask)
		if(goal == dp[mask ^ sub][id] + dp[sub][id] - a[id]) {
			solve(mask ^ sub, id);
			solve(sub, id);
			continue;
		}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	n *= m;
	rep(i, n) cin >> a[i];
	rep(i, k) {
		int x, y; cin >> x >> y; x--, y--;
		pos[i] = x * m + y;
	}

	rep(i, n) rep(j, n) {
		if(i == j) d[i][j] = 0;
		else if(i/m == j/m && abs(i-j) == 1) d[i][j] = a[j];
		else if(i%m == j%m && abs(i-j) == m) d[i][j] = a[j];
		else d[i][j] = inf;
	}
	rep(k, n) rep(i, n) rep(j, n) smin(d[i][j], d[i][k] + d[k][j]);

	rep(mask, 1 << k) rep(i, n) dp[mask][i] = inf;

	fer(mask, 1, 1 << k) {
		if((mask & (mask-1)) == 0) {
			rep(i, n) {
				int p = pos[__builtin_ctz(mask)];
				dp[mask][i] = d[p][i] + a[p];
			}
			continue;
		}
		rep(i, n) for(int sub = (mask-1) & mask; sub; sub = (sub-1) & mask)
			smin(dp[mask][i], dp[mask ^ sub][i] + dp[sub][i] - a[i]);
		rep(i, n) rep(j, n) smin(dp[mask][i], dp[mask][j] + d[j][i]);
	}

	int fmask = (1 << k) - 1;
	int ans = inf;

	rep(i, n) smin(ans, dp[fmask][i]);

	cout << ans << endl;

	rep(i, n/m) mat[i] = string(m, '.');
	solve(fmask, min_element(dp[fmask], dp[fmask] + n) - dp[fmask]);
	rep(i, n/m) cout << mat[i] << endl;

	{ return 0; }
}

