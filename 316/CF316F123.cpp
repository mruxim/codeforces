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

const int maxn = 1600 + 100;

int n, m;
int a[maxn][maxn];

bool isPainted (int x, int y)
{
	return x>=0 && y>=0 && x<n && y<m && a[x][y];
}

int isInside (int x, int y)
{
	for (int dx = -3; dx <= 3; dx++)
		for (int dy = -3; dy <= 3; dy++)	
			if (dx*dx+dy*dy != 18 && !isPainted (x+dx, y+dy))
				return 0;
	return 1;
}

bool isRay (int x, int y)
{
	if (a[x][y] != 1) return 0;
	for (int dx = -5; dx <= 5; dx++)
		for (int dy = -5; dy <= 5; dy++)	
			if (isPainted (x+dx, y+dy) && a[x+dx][y+dy] == 2)
				return 0;
	return 1;
}

void dfsRay (int x, int y)
{
	if (!isPainted (x, y)) return;
	if (a[x][y] != 8) return;
	a[x][y] = 0;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			dfsRay (x+dx, y+dy);
}

int dfs (int x, int y)
{
	if (!isPainted (x, y)) return 0	;
	int ret = 0;
	if (a[x][y] == 8)
		dfsRay (x, y), ret++;
	a[x][y] = 0;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			ret += dfs (x+dx, y+dy);
	return ret;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) rep (j, m) cin >> a[i][j];

	rep (i, n) rep (j, m)
		if (a[i][j])
			a[i][j] += isInside (i, j);

	rep (i, n) rep (j, m)
		if (isRay (i, j))
			a[i][j] = 8;

	vector <int> ans;

//	rep (i, n) { rep (j, m) cout << a[i][j] << ' '; cout << endl; }

	rep (i, n) rep (j, m) if (a[i][j] == 2)
		ans.pb (dfs (i, j));

	sort (all (ans));

	cout << sz(ans) << endl;
	rep (i, sz(ans)) cout << ans[i] << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
