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
#include <cmath>
#include <numeric>

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

int n, m;
int r[maxn], c[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		r[x] = c[y] = 1;
	}

	int ans = 0;
	fer (i, 1, n-1)
	{
		int x = i, y = n-1-x;
		if (y < x) break;
		if (x != y)
		{
			int cnt = 4;
			cnt -= r[x];
			cnt -= r[y];
			cnt -= c[x];
			cnt -= c[y];
			ans += cnt;
		}
		else
		{
			int cnt = 2;
			cnt -= r[x];
			cnt -= c[x];
			ans += (cnt > 0);
		}
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
