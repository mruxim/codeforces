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

const int maxn = 500 + 100;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, k;
string s[maxn];

int dfs (int x, int y)
{
	s[x][y] = 'O';
	int ret = 1;

	rep (i, 4)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if (s[nx][ny] != '.') continue;
		ret += dfs (nx, ny);
	}

	if (k && ret == 1)
		ret = 0, k--, s[x][y] = 'X';

	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> k;
	rep (i, n) cin >> s[i];

	rep (i, n) rep (j, m) if (s[i][j] == '.')
	{
		dfs (i, j);
		break;
	}

	rep (i, n) rep (j, m) if (s[i][j] == 'O') s[i][j] = '.';
	rep (i, n) cout << s[i] << endl;

	{ int _; cin >> _; return 0; }
}
