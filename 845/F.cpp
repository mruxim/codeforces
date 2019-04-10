// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 250 + 10;
const int maxm = 15;

int n, m;
char grid[maxn][maxm];
int dp[2][1 << maxm][2][3];

void addto(int &x, int y) { x += y; if(x >= mod) x -= mod; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> (m <= maxm ? grid[i][j] : grid[j][i]);
	if(maxm <= m) swap(n, m);

	dp[0][0][0][0] = 1;
	int cur = 0, nxt = 1;
	rep(i, n) rep(j, m) {
		rep(mask, 1 << m) rep(side, 2) rep(emp, 2) {
			int me = dp[cur][mask][side][emp];
			if(grid[i][j] == 'x') addto(dp[nxt][mask & ~(1 << j)][0][emp], me);
			else {
				addto(dp[nxt][mask | (1 << j)][j + 1 == m ? 0 : 1][emp], me);
				if(side || (mask >> j & 1) || emp == 0)
					addto(dp[nxt][mask][j + 1 == m ? 0 : side][emp + (!side && !(mask >> j & 1) ? 1 : 0)], me);
			}
		}
		swap(cur, nxt);
		memset(dp[nxt], 0, sizeof dp[nxt]);
	}

	int ans = 0;
	rep(mask, 1 << m) rep(emp, 2) addto(ans, dp[cur][mask][0][emp]);
	cout << ans << endl;

	return 0;
}

