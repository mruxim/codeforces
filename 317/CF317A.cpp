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

int main()
{
	ios::sync_with_stdio (false);

	ll x, y, m;
	cin >> x >> y >> m;
	if (x > y) swap (x, y);

	ll ans = 0;

	if (y >= m) { cout << 0 << endl; goto end; }
	if (y <= 0) { cout << -1 << endl; goto end; }

	ans = (y - x) / y, x += ans * y;

	while (1)
	{
		if (x > y) swap (x, y);
		if (y >= m) break;
		x += y;
		ans++;
	}

	cout << ans << endl;


	end:; { int _; cin >> _; return 0; }
}
