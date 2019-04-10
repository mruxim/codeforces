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

const int n = 24;

int m;
int dp[1<<n];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> m;
	rep (i, m)
	{
		string str; cin >> str;
		dp[1<<(str[0]-'a') | 1<<(str[1]-'a') | 1<<(str[2]-'a')]++;
	}

	rep (i, n) rof (mask, 1<<n, 0)
		if (mask >> i & 1) dp[mask] += dp[mask ^ (1<<i)];

	int ans = 0;
	rep (mask, 1<<n) ans ^= (m-dp[mask]) * (m-dp[mask]);

	cout << ans << endl;

	{ return 0; }
}

