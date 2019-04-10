// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 2 * 100000 + 999;
const int MAXl = 20 + 1;

int n, l;
char tmp[22];
int a[MAXn];
int ans[MAXn];
int dp[MAXl][1<<MAXl];

int conc (int x)
{
	if (x == 0) return l;
	for (int i = 0; ; i++)
		if ((a[x-1] ^ (a[x] >> i)) == ((a[x-1] >> (l-i)) << (l-i)))
			return i;
}

int main()
{
	scanf ("%d ", &n);
	rep (i, n)
	{
		gets (tmp);
		for (l = 0; tmp[l]; l++)
			a[i] = (a[i] << 1) | (tmp[l] - '0');
	}

	memset (dp, 60, sizeof dp);
	memset (ans, 60, sizeof ans);

	ans[0] = 0;
	rep (i, n) ans[0] += conc (i);
	dp[l][0] = ans[0];

	fer (i, 1, n)
	{
		ans[i] = 1<<30;
		rep (j, l+1)
			cmn (ans[i], dp[j][a[i] >> j] + j);
		ans[i] -= conc (i);
		rep (j, l+1)
			cmn (dp[j][a[i-1] & ((1 << (l-j))-1)], ans[i]);
	}

	int res = 1<<30;
	rep (i, n) cmn (res, ans[i]);
	cout << res << endl;
	{ int _; cin >> _; }
}
