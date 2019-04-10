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

const double pi = 2*acos(0);

int n, m;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	if ((m == 3 && n == 6) || (m == 3 && n == 5)) cout << -1 << endl;
	else if (m % 2)
	{
		rep (i, m)
		{
			double ang = 2*pi / m * i;
			int x = cos(ang) * 100000;
			int y = sin(ang) * 100000;
			cout << 900*x << ' ' << 900*y << endl;
			if (i < n-m)
				cout << x << ' ' << y << endl;
		}
	}
	else
	{
		rep (i, m)
		{
			double ang = pi / m * i;
			int x = cos(ang) * 1000000;
			int y = sin(ang) * 1000000;
			cout << x << ' ' << y << endl;
		}
		rep (i, n-m)
		{
			double ang = pi / (n-m) * i;
			int x = cos(ang) * 1000000;
			int y = sin(ang) * 1000000;
			cout << x << ' ' << 100000000 - y << endl;
		}
	}

	{ int _; cin >> _; return 0; }
}
