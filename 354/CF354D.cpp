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

const int inf = 1<<29;
const int maxn = 100000 + 100;
const int K = 800;

int n, t;
vector<int> v[maxn];
int dp[K], odp[K];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> t;
	rep (z, t)
	{
		int r, c;
		cin >> r >> c;
		v[c-1].pb (n-r);
	}
	rep (i, n) sort (all(v[i]));

	rep (i, n+1)
	{
		memcpy (odp, dp, sizeof dp);
		int mnv = *min_element (odp, odp+K);
		int rem = sz(v[i]);
		rep (j, K)
		{
			while (rem && v[i][sz(v[i])-rem] < j) rem--;
			dp[j] = min (i&&j+1<K ? odp[j+1] : inf, mnv + j*(j+1)/2 + (j?2:0)) + rem*3;
		}
	}

	cout << dp[0] << endl;

	{ return 0; }
}

