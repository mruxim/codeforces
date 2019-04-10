// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

const int maxn = 3000 + 100;

int n, k;
int p[maxn];
int any100[maxn], all0[maxn];

bool r[maxn][maxn];
int mn[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> p[i];
	rof (i, n, 0)
	{
		any100[i] = (p[i] == 100);
		all0[i] = (p[i] == 0);
		if (i+1 < n)
			any100[i] |= any100[i+1],
			all0[i] &= all0[i+1];
	}

	memset (mn, 50, sizeof mn);

	r[0][1] = true; mn[0][1] = 0;

	int ans = 0;

	rep (i, n) fer (j, i+1, n+1) if (r[i][j])
	{
		if (mn[i][j] <= k) ans++;
		if (j == n) continue;
		if (p[i] != 0 && !any100[j]) r[i][j+1] = 1, mn[i][j+1] = min (mn[i][j+1], mn[i][j]+1);
		if (p[i] != 100 && !all0[j]) r[j][j+1] = 1, mn[j][j+1] = min (mn[j][j+1], mn[i][j]+1);
		if (p[i] != 0 && !all0[j]) r[j+1][j+2] = 1, mn[j+1][j+2] = min (mn[j+1][j+2], mn[i][j]+1);
	}

	cout << ans + (r[n][n+1] && mn[n][n+1] <= k) << endl;

	{ int _; cin >> _; return 0; }
}
