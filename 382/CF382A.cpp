// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int main()
{
	ios_base::sync_with_stdio (false);

	string lp, rp, t;
	cin >> lp;
	int pos = lp.find ('|');
	rp = lp.substr (pos+1);
	lp = lp.substr (0, pos);
	cin >> t;

	int diff = sz(lp) - sz(rp);
	if (sz(t)%2 != abs(diff)%2 || sz(t) < abs(diff))
		cout << "Impossible" << endl;
	else
	{
		int use = (sz(t) - abs(diff)) / 2;
		lp += t.substr (0, use);
		rp += t.substr (use, use);
		if (diff > 0)
			rp += t.substr (2*use);
		else
			lp += t.substr (2*use);
		cout << lp << "|" << rp << endl;
	}

	{ return 0; }
}

