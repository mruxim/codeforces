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

template<class T> inline void smin(T &X,T Y){if(Y<X)X=Y;}
template<class T> inline void smax(T &X,T Y){if(X<Y)X=Y;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;

int n, m;
int d[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (z, n)
	{
		string s;
		cin >> s;
		s += "0";

		int p = -1;
		rep (i, sz(s))
		{
			if (s[i] == '0')
			{
				if (p+1 <= i-1)
					d[p+1][i-1]++;
				p = i;
			}
		}
	}

	rof (len, m, 0) rep (i, m)
	{
		int j = i+len;
		if (i) d[i][j] += d[i-1][j];
		if (j+1<m) d[i][j] += d[i][j+1];
		if (i && j+1<m) d[i][j] -= d[i-1][j+1];
	}

	int ans = 0;
	rep (i, m) fer (j, i, m) ans = max (ans, (j-i+1) * d[i][j]);

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
