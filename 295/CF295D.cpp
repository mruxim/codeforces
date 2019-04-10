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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;
const int mod = 1000000000 + 7;

int n, m;
int C[2*maxn][2*maxn];
int dp[maxn][maxn];

inline int fix (int v) { if (v >= mod) v -= mod; return v; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;

	rep (i, 2*maxn)
	{
		C[i][0] = C[i][i] = 1;
		fer (j, 1, i) C[i][j] = fix (C[i-1][j] + C[i-1][j-1]);
	}

	#define f(h,w) (C[2*h+w-1][w-1])

	rep (h, n) fer (w, 1, m)
		dp[h][w] = fix ((h ? dp[h-1][w] : 0) + f(h,w));

	int ans = 0;

	rep (h, n) fer (w, 1, m)
		ans = fix (ans + (m-w) * (ll)f(h,w) % mod * (ll)dp[n-h-1][w] % mod);

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
