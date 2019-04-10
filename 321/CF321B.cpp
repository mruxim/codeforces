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

const int maxn = 100 + 10;

int n, m;
int ciel[maxn];
vector<int> att, def;

bool mark[maxn];

int solve ()
{
	int ret = 0;

	reverse (ciel, ciel+m);

	rep (i, sz(att)+1)
	{
		if (i > m) break;
		int dmg = 0;
		rof (j, i, 0)
			if (att[j] <= ciel[i-j-1])
				dmg += ciel[i-j-1] - att[j];
			else
				dmg = -1e9;
		if (dmg < 0) break;
		ret = max (ret, dmg);
	}
	
	reverse (ciel, ciel+m);

	memset (mark, false, sizeof mark);
	int pos = 0;
	rep (i, sz(def))
	{
		while (pos < m && ciel[pos] <= def[i]) pos++;
		if (pos == m) return ret;
		mark[pos] = true;
		pos++;
	}

	vector<int> rem;
	rep (i, m) if (!mark[i]) rem.pb (ciel[i]);
	reverse (all(rem));

	rep (i, sz(att)+1)
	{
		if (i > sz(rem)) break;
		int dmg = 0;
		rof (j, i, 0)
			if (att[j] <= rem[i-j-1])
				dmg += rem[i-j-1] - att[j];
			else
				dmg = -1e9;
		if (dmg < 0) break;
		if (i == sz(att))
			dmg = accumulate (all(rem), 0) - accumulate (all(att), 0);
		ret = max (ret, dmg);
	}



	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n)
	{
		string str;
		int p;
		cin >> str >> p;
		if (str == "ATK") att.pb (p);
		else def.pb (p);
	}
	rep (i, m) cin >> ciel[i];

	sort (all(att));
	sort (all(def));
	sort (ciel, ciel+m);

	int ans = solve ();

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
