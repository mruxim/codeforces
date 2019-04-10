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

const int off = 100;

int n;
int c[2*off][2*off];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;

	c[off][off] = n;

	while (1)
	{
		bool con = false;
		rep (i, 2*off) rep (j, 2*off) if (c[i][j] >= 4)
		{
			c[i-1][j] += c[i][j]/4;
			c[i+1][j] += c[i][j]/4;
			c[i][j-1] += c[i][j]/4;
			c[i][j+1] += c[i][j]/4;
			c[i][j] %= 4;
			con = true;
		}
		if (!con) break;
	}

	int t; cin >> t;
	rep (z, t)
	{
		int x, y;
		cin >> x >> y;
		if (min (x, y) < -off || max (x, y) >= off)
			cout << 0 << endl;
		else
			cout << c[x+off][y+off] << endl;
	}

	{ return 0; }
}


