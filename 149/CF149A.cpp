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

int main()
{
	ios_base::sync_with_stdio (false);

	int k;
	int a[12];
	cin >> k;
	rep (i, 12) cin >> a[i];

	int ans = 99999;
	rep (i, 1<<12)
	{
		int s = 0;
		rep (j, 12) s += (i >> j & 1) * a[j];
		if (s >= k) ans = min (ans, __builtin_popcount (i));
	}

	cout << (ans == 99999 ? -1 : ans) << endl;

	{ int _; cin >> _; return 0; }
}
