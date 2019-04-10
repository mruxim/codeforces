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

const int maxn = 20;

int n, m;
string s[maxn];
int a[maxn][maxn];
int v[maxn], t;
int sum[1 << maxn];

int dp[1 << maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, m) cin >> a[i][j];

	rep(mask, 1 << n) dp[mask] = 1 << 28;

	rep(p, m) {
		rep(i, t) v[i] = 0; t = 0;
		for(char ch = 'a'; ch <= 'z'; ch++) {
			rep(i, n) if(s[i][p] == ch) v[t] |= 1 << i;
			if(v[t]) t++;
		}
		rep(mask, 1 << n) {
			if(mask) sum[mask] = sum[mask & (mask-1)] + a[__builtin_ctz(mask)][p];
			int fm = mask;
			rep(i, t) if(((v[i] & ~mask) & ((v[i] & ~mask) - 1)) == 0)
				fm |= v[i];
			if(sum[mask] < 0) return 0;
			smin(dp[fm], sum[mask]);
		}
	}

	rep(i, n) rep(mask, 1 << n) if(mask >> i & 1)
		smin(dp[mask ^ (1 << i)], dp[mask]);

	rep(mask, 1 << n) {
		rep(i, n) if(mask >> i & 1) {
			int cm = 1 << i;
			fer(j, i+1, n) if(mask >> j & 1 && dp[cm] == dp[cm | (1 << j)]) cm = cm | (1 << j);
			smin(dp[mask], dp[cm] + dp[mask ^ cm]);
		}
		rof(i, n, 0) if(mask >> i & 1) {
			int cm = 1 << i;
			rof(j, i, 0) if(mask >> j & 1 && dp[cm] == dp[cm | (1 << j)]) cm = cm | (1 << j);
			smin(dp[mask], dp[cm] + dp[mask ^ cm]);
		}
		rep(i, n) if(mask >> i & 1) {
			int cm = 1 << i;
			rof(j, n, 0) if(mask >> j & 1 && dp[cm] == dp[cm | (1 << j)]) cm = cm | (1 << j);
			smin(dp[mask], dp[cm] + dp[mask ^ cm]);
		}
		rof(i, n, 0) if(mask >> i & 1) {
			int cm = 1 << i;
			fer(j, 0, n) if(mask >> j & 1 && dp[cm] == dp[cm | (1 << j)]) cm = cm | (1 << j);
			smin(dp[mask], dp[cm] + dp[mask ^ cm]);
		}
	}

	cout << dp[(1 << n) - 1] << endl;

	return 0;
}

