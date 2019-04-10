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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = 1<<28;
const int maxn = 2000 + 100;

int n, m;
char s[maxn][maxn];
int d[maxn][maxn];
pii nxt[maxn][maxn];

void go (int x, int y)
{
	if (s[x][y] == '#') { d[x][y] = 0; return; }
	if (d[x][y] != -1) return;
	d[x][y] = -2;

	int nx = x, ny = y;
	if (s[x][y] == '^') nx--;
	if (s[x][y] == 'v') nx++;
	if (s[x][y] == '<') ny--;
	if (s[x][y] == '>') ny++;

	go (nx, ny);
	if (d[nx][ny] < 0) d[x][y] = inf;
	else d[x][y] = min (inf, d[nx][ny] + 1);
}

bool mark[maxn][maxn];

bool mv (int x, int y)
{
	if (s[x][y] == '#') return true;
	if (mark[x][y]) return false;
	mark[x][y] = true;
	int nx = x, ny = y;
	if (s[x][y] == '^') nx--;
	if (s[x][y] == 'v') nx++;
	if (s[x][y] == '<') ny--;
	if (s[x][y] == '>') ny++;
	return mv (nx, ny);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> s[i];

	memset (d, -1, sizeof d);
	rep (i, n) rep (j, m) if (d[i][j] == -1) go (i, j);

	rep (i, n) rep (j, m) if (d[i][j] == inf)
		{ cout << -1 << endl; return 0; }

	int mx = 0;
	rep (i, n) rep (j, m) smax (mx, d[i][j]);
	if (mx == 0) { cout << 0 << endl; return 0; }
	int ans = 2*mx-2;
	rep (i, n) rep (j, m) if (d[i][j] == mx)
		if (mv (i, j))
			ans++;
	cout << min (2*mx, ans) << endl;
	{ return 0; }
}

