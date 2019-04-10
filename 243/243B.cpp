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

int n, m, h, t;
vector <int> a[111111];
int b[111111];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m >> h >> t;
	rep (i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x].push_back (y);
		a[y].push_back (x);
	}

	memset (b, -1, sizeof b);
	rep (i, n) rep (j, sz(a[i]))
		if (b[i] == -1 || sz(a[a[i][j]]) > sz(a[b[i]]))
			b[i] = a[i][j];

	rep (i, n) if (sz(a[i]) > h && sz(a[b[i]]) > t)
	{
		cout << "YES" << endl;
		cout << i+1 << ' ' << b[i]+1 << endl;
		rep (j, sz(a[i])) if (a[i][j] != b[i]) if (h-- > 0)
			cout << a[i][j] + 1 << ' ';
		cout << endl;
		rep (j, sz(a[b[i]])) if (a[b[i]][j] != i) if (t-- > 0)
			cout << a[b[i]][j] + 1 << ' ';
		cout << endl;
		goto end;
	}
	cout << "NO" << endl;
end:
	{ int _; cin >> _; }
	return 0;
}
