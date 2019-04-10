// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000007;

int dp[111][111][111];
int C[555][555];

int main()
{
	ios::sync_with_stdio (false);

	rep (i, 555)
	{
		C[i][0] = C[i][i] = 1;
		fer (j, 1, i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	int n, m, kk;
	cin >> n >> m >> kk; //if (kk > (m+1)/3) kk = (m+1)/3;

	rep (i, 111) rep (k, 111) dp[i][0][k] = 1;

	fer(k, 1, kk+1) fer(i, 2, m+1) for(int j = 2; j <= n; j += 2) {
		dp[i][j][k] = dp[i-1][j][k];
		fer(ii, 2, i+1) for(int jj = 2*ii-2; jj <= j; jj += 2) {
			dp[i][j][k] += dp[max(0, i-ii-1)][j-jj][k-1] * (ll)C[jj-ii][ii-2] % mod;
			if(dp[i][j][k] >= mod) dp[i][j][k] -= mod;
		}
		cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
	}

	int ans = 0;
	for(int i = 2; i <= n; i++)
		ans = (ans + dp[m][i][kk]) % mod;
	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
