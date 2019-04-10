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

const int maxn = 20 + 1;

int n;
string s[maxn];
int dp[2*maxn][1<<maxn];
bool vis[2*maxn][1<<maxn];

int go (int sum, int mask)
{
	if (vis[sum][mask]) return dp[sum][mask];

	int tmask = 0;
	int add = 0;
	rep (i, n) if (mask >> i & 1)
	{
		int j = sum - i;
		if (s[i][j] == 'a') add = 1;
		if (s[i][j] == 'b') add = -1;
		if (i+1<n) tmask |= 1 << (i+1);
		if (j+1<n) tmask |= 1<< i;
	}

	if (sum == 2*n-2) return add;

	int ret = 99999;
	if (sum % 2) ret *= -1;

	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		int cmask = 0;
		rep (i, n) if ((tmask >> i & 1) && s[i][sum+1-i] == ch)
			cmask |= 1 << i;
		if (cmask == 0) continue;

		int cur = go (sum+1, cmask);
		if (sum % 2) ret = max (ret, cur);
		else ret = min (ret, cur);
	}

	vis[sum][mask] = true;
	return dp[sum][mask] = ret + add;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> s[i];

	int ans = go (0, 1);

//	cerr << ans << endl;
	cout << (ans > 0 ? "FIRST" : ans == 0 ? "DRAW" : "SECOND") << endl;

	{ int _; cin >> _; return 0; }
}
