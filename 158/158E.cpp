// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
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

const int MAXn = 4000 + 5;

int n, k;
int dp[MAXn][MAXn];

inline int con (int e, int x, int y)
{
	return max (e, x) + y;
}

int main()
{
	memset (dp, 60, sizeof dp);
	dp[0][0] = 0;
	cin >> n >> k;

	int ans = 0;

	rep (i, n)
	{
		int x, y;
		cin >> x >> y; x--;

		if (i <= k)
			cmx (ans, x);
		else
			cmx (ans, x - dp[i][k]);

		dp[i+1][0] = con (dp[i][0], x, y);
		fer (j, 1, i+2)
			dp[i+1][j] = min (con (dp[i][j], x, y), dp[i][j-1]);
	}
	if (k == n) ans = 86400;
	cmx (ans, 86400 - dp[n][k]);
	cout << ans << endl;
	{ int _; cin >> _; }
}
