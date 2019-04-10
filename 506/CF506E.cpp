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

const int mod = 10007;
const int maxn = 200 + 2;
const int N = 2 * maxn;

int mat[30][N][N], t[N][N];
		
void mul(int a[N][N], int b[N][N], int c[N][N]) {
	rep(i, N) rep(j, N) {
		rep(k, N) {
			c[i][k] += c[i][j] * c[j][k];
			if((k&15) == 15) c[i][k] %= mod;
		}
		c[i][k] %= mod;
	}
}

int n, k;
string s;
int dp[maxn][maxn][maxn];

void init() {
	rep(i, N/2) dp[0][i][i] = 25;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	init();

	cin >> s;
	cin >> k;
	
	n = sz(s);
	
	rof(i, n+1, 0) fer(j, i, n+1) rep(k, j-i+1)
		if(j-i == 0)
			dp[i][j][k] = (k == 0 ? 1 : 0);
		else if(s[i] != s[j-1])
			!k ? 0 : dp[i][j][k] = dp[i+1][j][k-1] + dp[i][j-1][k-1];
		else
			dp[i][j][k] = dp[i+1][max(i+1, j-1)][k];

	rep(p24, n) if(dp[0][n][p24] > 0) {
		int mul = dp[0][n][p24];
		int p25 = (n - p24 + 1) / 2;

	}

	return 0;
}

