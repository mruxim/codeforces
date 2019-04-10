
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

const int maxn = 3000 + 10;

int n;
pii marble[maxn];
ll dp[maxn];


int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> marble[i].X >> marble[i].Y;
	sort (marble, marble+n);

	dp[0] = marble[0].Y;
	marble[n] = {0, 0};
	fer (i, 1, n+1)
	{
		ll sumx = 0;
		dp[i] = 1LL<<62;
		rof (j, i, 0)
		{
			sumx += marble[j].X;
			smin (dp[i], dp[j] + sumx - (i-j) * (ll)marble[j].X);
		}
		dp[i] += marble[i].Y;
	}

	cout << dp[n] << endl;

	{ return 0; }
}

