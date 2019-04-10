// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxm = 100000 + 100;

int n, m, p;
int d[maxn];
ll dis[maxn];
ll h[maxm];
ll dp[maxn][105];
int st[maxm], top, pos;
ll tim[maxm];
ll sum[maxm];

ll calc (int i, int k, int j)
{
	return ((dp[i][j] + sum[i]) - (dp[k][j] + sum[k])) / (i - k) + 1;
}

int main()
{
	ios::sync_with_stdio (false);

/**/	cin >> n >> m >> p;
	fer (i, 1, n) cin >> d[i], dis[i] = dis[i-1] + d[i];
	fer (i, 0, m) { int t; cin >> h[i] >> t; h[i] = t - dis[h[i]-1]; }
/*/
	cin >> m >> p; rep (i, m) cin >> h[i];
/**/
	sort (h, h+m);
	ll mint = h[0];
	rep (i, m) h[i] -= mint;
	rep (i, m) sum[i] = (i ? sum[i-1] : 0) + h[i];
	rep (j, p)
	{
		pos = top = 0;
		rep (i, m)
		{
			int last = max (h[i], mint);
			if (j == 0)
			{
				dp[i][j] = last * (ll)(i+1) - sum[i];
				continue;
			}

			while (pos+1 < top && tim[pos+1] <= last) pos++;
			
			int prev = (pos < top ? st[pos] : i);
			ll cur = last * (ll)(i - prev) - sum[i] + sum[prev];

			dp[i][j] = dp[prev][j-1] + cur;

			st[top++] = i;
			if (top >= 2)
				tim[top-1] = calc (st[top-1], st[top-2], j-1);
			else
				tim[top-1] = 0;
			while (top >= 2 && (tim[top-1] = calc (st[top-1], st[top-2], j-1)) <= tim[top-2])
				st[top-2] = st[top-1], tim[top-2] = tim[top-1], top--;
		}
	}

	cout << dp[m-1][p-1] << endl;

	{ int _; cin >> _; return 0; }
}
