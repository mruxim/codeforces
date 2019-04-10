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

int c2i (char c)
{
	return c <= '9' ? c - '0' : c - 'A' + 10;
}

int conv (string s, int r)
{
	int ret = 0;
	rep (i, sz(s)) if (c2i (s[i]) >= r) return -1;
	rep (i, sz(s)) { ret = ret * r + c2i (s[i]); if (ret > 1000) return -1; }
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	string str;
	cin >> str;

	string a, b;
	rep (i, sz(str)) if (str[i] != ':') a += str[i]; else break;
	rof (i, sz(str), 0) if (str[i] != ':') b = str[i] + b; else break;

	vector<int> ans;
	fer (r, 2, 1000)
	{
		int x = conv (a, r);
		int y = conv (b, r);
		if (0 <= x && x < 24 && 0 <= y && y < 60) ans.pb (r);
	}

	if (sz(ans) == 0) cout << 0 << endl;
	else if (sz(ans) > 100) cout << -1 << endl;
	else
	{
		rep (i, sz(ans)) cout << ans[i] << ' ';
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
