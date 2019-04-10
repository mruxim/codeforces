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

ll n;
ll p10[20];
bool vis[20][10];
vector<ll> dp[20][10];
vector<ll> dig[100];

vector<ll> go (int k, int p)
{
	if (vis[k][p]) return dp[k][p];
	vis[k][p] = true;
	int cur = n / p10[k-1] % 10 + p * 10;
	if (k == 1) return dig[cur];
	rep (i, 10)
	{
		if (i > cur) break;
		if (sz(dig[cur-i]) == 0) continue;
		vector<ll> tmp = go (k-1, i);
		if (sz(tmp) == 0) continue;
		rep (j, 6) tmp[j] += dig[cur-i][j] * p10[k-1];
		return dp[k][p] = tmp;
	}
	return dp[k][p] = vector<ll>();
}

int main()
{
	ios_base::sync_with_stdio (false);

	p10[0] = 1;
	fer (i, 1, 20) p10[i] = p10[i-1] * 10;

	rep (i, 3*3*3*3*3*3)
	{
		vector<ll> tmp;
		int x = i;
		rep (j, 6) tmp.pb (x%3==0 ? 0 : x%3==1 ? 4 : 7), x /= 3;
		ll sum = accumulate (all(tmp), 0);
		dig[sum] = tmp;
	}

	int TTT;
	for (cin >> TTT; TTT--; )
	{
		cin >> n;
		memset (vis, false, sizeof vis);
		vector<ll> ans = go (18, 0);
		if (sz(ans) == 0)
			cout << -1 << endl;
		else
		{
			rep (i, 6) cout << ans[i] << ' ';
			cout << endl;
		}
	}


	{ int _; cin >> _; return 0; }
}
