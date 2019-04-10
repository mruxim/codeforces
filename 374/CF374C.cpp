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

const int maxn = 1000 + 100;
const int INF = 1<<27;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
char nxt[128];
string s[maxn];
int d[maxn][maxn];

inline bool in (int x, int y)
{
	return min (x, y) >= 0 && x < n && y < m;
}

int go (int x, int y)
{
	if (d[x][y]) return d[x][y];
	d[x][y] = -1;
	rep (i, 4) if (in (x+dx[i], y+dy[i]) && s[x+dx[i]][y+dy[i]] == nxt[s[x][y]])
	{
		int xx = x+dx[i], yy = y+dy[i];
		int t = go (xx, yy);
		if (t < 0) return d[x][y] = INF;
		d[x][y] = min (d[x][y], -t - 1);
	}
	d[x][y] = min (-d[x][y], INF);
	return d[x][y];
}

int main()
{
	ios_base::sync_with_stdio (false);

	nxt['D'] = 'I';
	nxt['I'] = 'M';
	nxt['M'] = 'A';
	nxt['A'] = 'D';

	cin >> n >> m;
	rep (i, n) cin >> s[i];

	int	ans = 0;
	rep (i, n) rep (j, m)
	{
		if (d[i][j] == 0)
			go (i, j);
		if (s[i][j] == 'D')
			ans = max (ans, d[i][j]);
	}

	ans /= 4;
	if (ans == 0) cout << "Poor Dima!" << endl;
	else if (ans >= INF/4) cout << "Poor Inna!" << endl;
	else cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
