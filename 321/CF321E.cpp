// .... .... .....!
// P..... C.....!

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
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 4000 + 100;
const int maxm = 800 + 50;

int n, m;
int s[maxn][maxn];

int dp[maxn][maxm];

inline int cost (int i, int j, int prev)
{
	return dp[prev][j-1] + s[i][i] - s[i][prev] - s[prev][i] + s[prev][prev];
}

int bs (int j, int i, int last)
{
	int lo = i, hi = n+1;
	while (hi - lo > 1)
	{
		int md = (lo + hi) / 2;
		if (cost (md, j, i) < cost (md, j, last))
			hi = md;
		else
			lo = md;
	}
	return hi;
}

pii goods[maxn];

int main()
{
	cin >> n >> m;
	rep (i, n) rep (j, n) s[i+1][j+1] = (getchar(), getchar()) - '0';

	rep (i, n) rep (j, n) s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + s[i+1][j+1];

	memset (dp, 50, sizeof dp);

	dp[0][0] = 0;

	fer (j, 1, m+1)
	{
		int head = 0, tail = 0;
		goods[tail++] = pii (0, 1);

		fer (i, 1, n+1)
		{
			while (head+1 < tail && goods[head+1].Y <= i) head++;
			dp[i][j] = cost (i, j, goods[head].X);

			while (head < tail-1 && cost (goods[tail-1].Y, j, i) < cost (goods[tail-1].Y, j, goods[tail-1].X))
				tail--;

			int when = bs (j, i, goods[tail-1].X);
			if (when != n+1)
				goods[tail++] = pii (i, when);
		}
	}

	cout << dp[n][m]/2 << endl;

	{ int _; cin >> _; return 0; }
}

