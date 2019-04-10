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

const int maxn = 100 + 10;
const int pc = 11;
const int maxk = 20;

const int p[pc] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int n;
int a[maxn];
int b[maxn];
vector<int> op;
int ps[88];
int dp[maxn][maxk][1<<pc];
int uk[maxn][maxk][1<<pc];
int um[maxn][maxk][1<<pc];
int uv[maxn][maxk][1<<pc];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	fer(i, 32, 700) {
		bool ip = true;
		fer(j, 2, i) if(i % j == 0) ip = false;
		if(ip) op.pb(i);
	}

	fer(j, 1, 88) {
		int x = j;
		rep(i, pc) while(x % p[i] == 0) x /= p[i], ps[j] |= 1 << i;
		if(x > 1) ps[j] = -1;
	}

	cin >> n;
	rep(i, n) cin >> a[i];

	memset(dp, 50, sizeof dp);
	dp[0][0][0] = 0;
	fer(i, 0, n) fer(k, 0, maxk) rep(mask, 1<<pc) if(dp[i][k][mask] < 1e6) {
		smin(dp[i+1][k+1][mask], dp[i][k][mask] + abs(a[i] - op[k]));
		if(dp[i+1][k+1][mask] == dp[i][k][mask] + abs(a[i] - op[k]))
			uk[i+1][k+1][mask] = k, um[i+1][k+1][mask] = mask, uv[i+1][k+1][mask] = op[k];

		fer(v, 1, 88) if(ps[v] != -1 && (ps[v] & mask) == 0) {
			smin(dp[i+1][k][mask | ps[v]], dp[i][k][mask] + abs(a[i] - v));
			if(dp[i+1][k][mask | ps[v]] == dp[i][k][mask] + abs(a[i] - v))
				uk[i+1][k][mask | ps[v]] = k, um[i+1][k][mask | ps[v]] = mask, uv[i+1][k][mask | ps[v]] = v;
		}
	}

	int ans = 1<<30;
	int ci = -1, ck = -1, cm = -1;
	fer(k, 0, maxk) rep(mask, 1<<pc) {
		smin(ans, dp[n][k][mask]);
		if(ans == dp[n][k][mask]) ci = n, ck = k, cm = mask;
	}
	while(ci != -1) {
		b[ci-1] = uv[ci][ck][cm];
		int nk = uk[ci][ck][cm];
		int nm = um[ci][ck][cm];
		ci--;
		ck = nk;
		cm = nm;
	}

	rep(i, n) cout << b[i] << ' '; cout << endl;

	{ return 0; }
}

