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

int n, d, l;
int a[111];

bool m[105][10000*2+100];

bool go (int p, int r)
{
	if (p == n) return r == 0;
	if (m[p][r+10000+50]) return false;

	if (r <= 0)
	{
		fer (i, 1, l+1) if (go (p+1, i - r))
		{
			a[p] = i;
			return true;
		}
	}
	else if ((n - p) % 2 == 1 && 1 <= r && r <= l)
	{
		a[p] = r;
		fer (k, p+1, n) a[k] = 1;
		return true;
	}
	else if ((n - p) % 2 == 0 && r == 0)
	{
		fer (k, p, n) a[k] = 1;
		return true;
	}
	else if (r >= l)
	{
		if (go (p+1, l - r))
		{
			a[p] = l;
			return true;
		}
	}
	else
	{
		rof (i, l+1, 1) if (go (p+1, i - r))
		{
			a[p] = i;
			return true;
		}
	}
	m[p][r+10000+50] = true;
	return false;
}

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> d >> l;

	if (go (0, d))
	{
		rep (i, n) cout << a[i] << ' ';
		cout << endl;
	}
	else
		cout << -1 << endl;

	{ int _; cin >> _; }
	return 0;
}
