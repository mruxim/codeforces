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

const int mod = 1000000000 + 7;
const int maxn = 3000 + 10;

int n, m;
string s[maxn];
int c[maxn][maxn];

void calc (int sx, int sy)
{
	c[sx][sy] = 1;
	rep (i, n) rep (j, m)
		if (s[i][j] == '.')
		{
			if (i == sx && j == sy) c[i][j] = 1;
			else
			{
				c[i][j] = 0;
				if (i) c[i][j] += c[i-1][j];
				if (j) c[i][j] += c[i][j-1];
				if (c[i][j] >= mod) c[i][j] -= mod;
			}
		}
		else c[i][j] = 0;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> s[i];
	calc (0, 1);
	int b1 = c[n-1][m-2], g1 = c[n-2][m-1];
	calc (1, 0);
	int g2 = c[n-1][m-2], b2 = c[n-2][m-1];
	cout << (g1*(ll)g2 % mod - b1*(ll)b2 % mod + mod) % mod << endl;

	{ return 0; }
}

