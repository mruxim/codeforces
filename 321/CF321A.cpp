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

inline pii move (pii cur, char dir)
{
	if (dir == 'U') return pii (cur.X, cur.Y+1);
	if (dir == 'D') return pii (cur.X, cur.Y-1);
	if (dir == 'L') return pii (cur.X-1, cur.Y);
	if (dir == 'R') return pii (cur.X+1, cur.Y);
}

set<pii> st;

int main()
{
	ios_base::sync_with_stdio (false);

	pii target;
	string s;

	cin >> target.X >> target.Y;
	cin >> s;

	pii cur(0, 0);
	
	rep (i, 5000)
		rep (j, sz(s))
		{
			st.insert (cur);
			cur = move (cur, s[j]);
		}

	bool yes = false;

	rep (i, 500000)
	{
		if (st.find (target) != st.end()) { yes = true; break; }
		target.X -= cur.X, target.Y -= cur.Y;
		if (abs (target.X) > 1e9 + 5 || abs (target.Y) > 1e9 + 5) break;
	}

	cout << (yes ? "Yes" : "No") << endl;

	{ int _; cin >> _; return 0; }
}
