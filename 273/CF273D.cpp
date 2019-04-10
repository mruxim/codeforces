	// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 150 + 5;

int n, m;
int dp[maxn][maxn][maxn][5];
int gl[maxn][maxn], gr[maxn][maxn], se[maxn][maxn], bw[maxn][maxn];

inline int add (int x, int y)
{
	x += y;
	if (x >= mod) return x-mod;
	return x;
}
inline int sub (int x, int &y)
{
	x -= y;
	if (x < 0) return x+mod;
	return x;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) fer (j, i, n)
		dp[0][i][j][0] = 1;

	fer (k, 1, m)
	{
		rof (i, n, 0)
		{
			se[i][i] = dp[k-1][i][i][0];
			if (i+1 == n) continue;
			se[i][i+1] = add (se[i][i], add (se[i+1][i+1], dp[k-1][i][i+1][0]));
			fer (j, i+2, n)
			{
				se[i][j] = add (se[i][j-1], se[i+1][j]) - se[i+1][j-1];
				if (se[i][j] < 0) se[i][j] += mod;
				se[i][j] = add (se[i][j], dp[k-1][i][j][0]);
			}
		}

		rof (i, n, 0)
		{
			bw[i][i] = dp[k-1][i][i][2];
			if (i+1 == n) continue;
			bw[i][i+1] = add (bw[i][i], add (bw[i+1][i+1], dp[k-1][i][i+1][2]));
			fer (j, i+2, n)
			{
				bw[i][j] = add (bw[i][j-1], bw[i+1][j]) - bw[i+1][j-1];
				if (bw[i][j] < 0) bw[i][j] += mod;
				bw[i][j] = add (bw[i][j], dp[k-1][i][j][2]);
			}
		}

		rof (i, n, 0)
		{
			gl[i][i] = dp[k-1][i][i][1];
			if (i+1 == n) continue;
			gl[i][i+1] = add (gl[i][i], add (gl[i+1][i+1], dp[k-1][i][i+1][1]));
			fer (j, i+2, n)
			{
				gl[i][j] = add (gl[i][j-1], gl[i+1][j]) - gl[i+1][j-1];
				if (gl[i][j] < 0) gl[i][j] += mod;
				gl[i][j] = add (gl[i][j], dp[k-1][i][j][1]);
			}
		}

		rof (i, n, 0)
		{
			gr[i][i] = dp[k-1][i][i][3];
			if (i+1 == n) continue;
			gr[i][i+1] = add (gr[i][i], add (gr[i+1][i+1], dp[k-1][i][i+1][3]));
			fer (j, i+2, n)
			{
				gr[i][j] = add (gr[i][j-1], gr[i+1][j]) - gr[i+1][j-1];
				if (gr[i][j] < 0) gr[i][j] += mod;
				gr[i][j] = add (gr[i][j], dp[k-1][i][j][3]);
			}
		}

		rep (i, n) fer (j, i, n)
		{
			dp[k][i][j][0] = add (se[i][j], 1);
			if (i)
			{
				dp[k][i][j][1] = add (dp[k][i][j][1], gl[0][j]);
				dp[k][i][j][1] = sub (dp[k][i][j][1], gl[0][i-1]);
				dp[k][i][j][1] = sub (dp[k][i][j][1], gl[i+1][j]);
				dp[k][i][j][1] = add (dp[k][i][j][1], se[0][j]);
				dp[k][i][j][1] = sub (dp[k][i][j][1], se[i][j]);
				dp[k][i][j][1] = sub (dp[k][i][j][1], se[0][i-1]);
			}
			if (j < n-1)
			{
				dp[k][i][j][3] = add (dp[k][i][j][3], gr[i][n-1]);
				dp[k][i][j][3] = sub (dp[k][i][j][3], gr[j+1][n-1]);
				dp[k][i][j][3] = sub (dp[k][i][j][3], gr[i][j-1]);
				dp[k][i][j][3] = add (dp[k][i][j][3], se[i][n-1]);
				dp[k][i][j][3] = sub (dp[k][i][j][3], se[i][j]);
				dp[k][i][j][3] = sub (dp[k][i][j][3], se[j+1][n-1]);
			}
					dp[k][i][j][2] = add (dp[k][i][j][2], bw[0][n-1]);
			if (j>0+0)	dp[k][i][j][2] = sub (dp[k][i][j][2], bw[0][j-1]);
			if (i<n-1)	dp[k][i][j][2] = sub (dp[k][i][j][2], bw[i+1][n-1]);
			if (i+1<=j-1)	dp[k][i][j][2] = add (dp[k][i][j][2], bw[i+1][j-1]);

					dp[k][i][j][2] = add (dp[k][i][j][2], se[0][n-1]);
					dp[k][i][j][2] = sub (dp[k][i][j][2], se[0][j]);
					dp[k][i][j][2] = sub (dp[k][i][j][2], se[i][n-1]);
					dp[k][i][j][2] = add (dp[k][i][j][2], se[i][j]);

					dp[k][i][j][2] = add (dp[k][i][j][2], gl[0][n-1]);
					dp[k][i][j][2] = sub (dp[k][i][j][2], gl[0][j]);
			if (i<n-1)	dp[k][i][j][2] = sub (dp[k][i][j][2], gl[i+1][n-1]);
			if (i+1<=j)	dp[k][i][j][2] = add (dp[k][i][j][2], gl[i+1][j]);

					dp[k][i][j][2] = add (dp[k][i][j][2], gr[0][n-1]);
			if (j>0+0)	dp[k][i][j][2] = sub (dp[k][i][j][2], gr[0][j-1]);
					dp[k][i][j][2] = sub (dp[k][i][j][2], gr[i][n-1]);
			if (i+1<=j)	dp[k][i][j][2] = add (dp[k][i][j][2], gr[i][j-1]);
//			cerr << bw[0][n-1] << endl;
//			cerr << k << ' ' << i << ' ' << j << " --> " << dp[k][i][j][0] << ' ' << dp[k][i][j][1] << ' ' << dp[k][i][j][3] << ' ' << dp[k][i][j][2] << endl;
		}
	}

	int ans = 0;
	rep (k, m) rep (i, n) fer (j, i, n)
	{
		ans = add (ans, dp[k][i][j][0]);
		ans = add (ans, dp[k][i][j][1]);
		ans = add (ans, dp[k][i][j][2]);
		ans = add (ans, dp[k][i][j][3]);
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
