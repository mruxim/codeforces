// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500 + 10;

int n;
char a[maxn][maxn];
bool can[maxn][maxn];
bool in[maxn][maxn][maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	rep (i, n) rep (j, n) a[i][j] -= '0';

	memset (can, true, sizeof can);

	rep (i, n) rep (j, n)
	{
		vector <int> ini, inj, inb;
		rep (k, n)
			if (a[i][k] && a[j][k]) inb.push_back (k);
			else if (a[i][k]) ini.push_back (k);
			else if (a[i][k]) inj.push_back (k);
		rep (x, sz(ini)) rep (y, sz(inj)) can[ini[x]][inj[y]] = can[inj[y]][ini[x]] = false;
	}


	{ int _; cin >> _; }
	return 0;
}
