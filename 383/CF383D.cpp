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

const int mod = 1000000000+7;
const int maxn = 1000 + 100;
const int maxs = 10000 + 100;

int n;
int a[maxn];
int _c[2*maxs], *c = _c+maxs;
int _oc[2*maxs], *oc = _oc+maxs;
int ans;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];

	c[0] = 1;
	rep (i, n)
	{
		copy (c-maxs, c+maxs, oc-maxs);
		fer (j, -maxs, maxs)
		{
			c[j] = 0;
			if (j-a[i] >= -maxs) c[j] += oc[j-a[i]];
			if (j+a[i] < maxs) c[j] += oc[j+a[i]];
			if (c[j] >= mod) c[j] -= mod;
		}
		ans += c[0]; if (ans >= mod) ans -= mod;
		c[0]++;
	}

	cout << ans << endl;

	{ return 0; }
}

