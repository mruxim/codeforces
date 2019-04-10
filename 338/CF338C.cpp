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

const int INF = 1<<30;;
const int maxn = 8 + 1;

int n;
ll a[maxn];
int par[maxn];
ll mul[maxn];
int cnt[maxn];
map <ll, int> mp;

int f (ll x)
{
	ll y = x;
	if (mp.count (x)) return mp[x];
	int res = 0;
	for (ll p = 2; p*p <= x; p++)
		while (x % p == 0) x /= p, res++;
	if (x > 1) res++;
	return mp[y] = res;
}

int ans = 999999999;

void go (int pos)
{
	if (pos == n)
	{
		int cur = 0;
		rep (i, n)
		{
			int tmp = f (a[i] / mul[i]);
			cur += 1 + tmp;
			if (mul[i] == 1 && tmp == 1)
				cur--;
		}
		if (cnt[n] > 1) cur++;
		ans = min (ans, cur);
		return;
	}
	for (int i = pos+1; i <= n; i++) if (i == n || (a[pos] <= a[i] / mul[i]) && a[i] % (a[pos] * mul[i]) == 0)
	{
		par[pos] = i;
		if (i < n) mul[i] *= a[pos];
		cnt[i]++;
		go (pos+1);
		if (i < n) mul[i] /= a[pos];
		cnt[i]--;
	}
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	sort (a, a+n);
	n = unique (a, a+n) - a;
	a[n] = 0;

	rep (i, n+2) mul[i] = 1;

	go (0);

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
