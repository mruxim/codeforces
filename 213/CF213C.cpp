// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 300 + 10;

int n;
int a[maxn][maxn];
int dp[2*maxn][maxn][maxn];

int main()
{
	memset (dp, -50, sizeof dp);
	cin >> n;
	rep (i, n) rep (j, n) cin >> a[i][j];

	dp[0][0][0] = a[0][0];
	fer (d, 1, 2*n-1) rep (i1, n) fer (i2, i1, n)
	{
		int j1 = d - i1, j2 = d - i2;
		if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) continue;
		if (i1 && i2) cmx (dp[d][i1][i2], dp[d-1][i1-1][i2-1]);
		if (i1 && j2) cmx (dp[d][i1][i2], dp[d-1][i1-1][i2]);
		if (j1 && i2) cmx (dp[d][i1][i2], dp[d-1][i1][i2-1]);
		if (j1 && j2) cmx (dp[d][i1][i2], dp[d-1][i1][i2]);
		dp[d][i1][i2] += a[i1][j1] + a[i2][j2];
		if (i1 == i2) dp[d][i1][i2] -= a[i1][j1];
	}
	cout << dp[2*n-2][n-1][n-1] << endl;

	{ int _; cin >> _; }
}
