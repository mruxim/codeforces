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

int n, m;
char s[55][55];
int a[55], b[55];

bool ok ()
{
	rep (i, n)
	{
		int cnt = 0;
		rep (j, m) cnt += (s[i][j] != (j ? s[i][j-1] : 'W'));
		if (cnt > 2) return 0;
	}
	rep (i, m)
	{
		int cnt = 0;
		rep (j, n) cnt += (s[j][i] != (j ? s[j-1][i] : 'W'));
		if (cnt > 2) return 0;
	}
	memset (a, 60, sizeof a);
	memset (b, -1, sizeof b);

	rep (i, n) rep (j, m) if (s[i][j] == 'B')
		a[i] = min (a[i], j), b[i] = max (b[i], j);

	rep (i, n) rep (j, n) if (b[i] != -1 && b[j] != -1 && s[i][a[j]] == 'W' && s[j][b[i]] == 'W')
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> s[i];
	
	cout << (ok() ? "YES" : "NO") << endl;

	{ int _; cin >> _; return 0; }
}
