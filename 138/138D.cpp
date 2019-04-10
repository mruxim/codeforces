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

const int maxn = 20 + 2;
const int maxs = 40 + 5;

int n, m;
char a[maxn][maxn];
int cache[maxs][maxs][maxs][maxs];

int &get (int s1, int s2, int d1, int d2) { return cache[s1][s2][d1+maxn][d2+maxn]; }

int calc (int s1, int s2, int d1, int d2)
{
	if (s1 > s2 || d1 > d2) return 0;
	int &ret = get (s1, s2, d1, d2);
	if (ret != -1) return ret;

	vector<int> v;
	for (int s = s1; s <= s2; s++) if ((s1+s) % 2 == 0)
		for (int d = d1; d <= d2; d++) if ((d1+d) % 2 == 0)
		{
			int x = (s+d)/2, y = (s-d)/2;
			if (x<0 || y<0 || x>=n || y>=m) continue;

			int tmp;
			if (a[x][y] == 'X')
				tmp=calc (s1, x+y-2, d1, x-y-2) ^
					calc (s1, x+y-2, x-y+2, d2) ^
					calc (x+y+2, s2, d1, x-y-2) ^
					calc (x+y+2, s2, x-y+2, d2);
			else if (a[x][y] == 'L')
				tmp=calc (s1, x+y-2, d1, d2) ^
					calc (x+y+2, s2, d1, d2);
			else if (a[x][y] == 'R')
				tmp=calc (s1, s2, d1, x-y-2) ^
					calc (s1, s2, x-y+2, d2);
			v.pb (tmp);
		}

	sort (all(v));
	ret = 0;
	rep (i, sz(v)) if (ret == v[i]) ret++;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i];

	memset (cache, -1, sizeof cache);

	int nim1 = calc (0, (n+m-2)/2*2, (-m+1)/2*2, (n-1)/2*2);
	int nim2 = calc (1, (n+m-1)/2*2-1, -m/2*2+1, n/2*2-1);

	cout << ((nim1 ^ nim2) ? "WIN" : "LOSE") << endl;

	{ int _; cin >> _; return 0; }
}
