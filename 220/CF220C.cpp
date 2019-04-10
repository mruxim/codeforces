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

int n;
int a[111111], b[111111], ra[111111];
set <pii> s;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i], a[i]--, ra[a[i]] = i;
	rep (i, n) cin >> b[i], b[i]--;

	rep (i, n) s.insert (pii (ra[b[i]] - i, i));
	
	rep (i, n)
	{
		int ans = 999999;
		auto x = s.upper_bound (pii (-i, 0));
		if (x != s.end())
			ans = min (ans, abs (x->first + i));
		if (x != s.begin())
			x--, ans = min (ans, abs (x->first + i));
		cout << ans << endl;
		x = s.lower_bound (pii (ra[b[i]] - i, i));
		s.erase (x);
		s.insert (pii (x->first - n, i));
	}
	cout << endl;

	{ int _; cin >> _; }
	return 0;
}
