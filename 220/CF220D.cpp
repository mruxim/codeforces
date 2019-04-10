// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000007;
const int maxw = 4000 + 100;


int w, h;
int cache[maxw];

int cnt (int a, int b) // gcd (a, b) = 1
{
	if (cache[a+b] != -1) return cache[a+b];
	int ret = 0;

	rep (m, maxw)
	{
		int len = (a+b) * m;
		if (h+1-len <= 0) break;
		ret += (m ? 2 : 1) * (h+1-len);
	}

	return cache[a+b] = ret;
}

pii hmw (int k)
{
	int tot = k*(ll)k*k % mod;
	int x = k/2, y = k-x;
	int sam = (x*(ll)x*x + y*(ll)y*y) % mod;
	return pii (sam, (tot - sam + mod) % mod);
}

int pm (int x, int p)
{
	int ret = 1;
	for (int i = 0; (1<<i) <= p; i++)
	{
		if (p >> i & 1) ret = (ret * (ll)x) % mod;
		x = x*(ll)x % mod;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio (false);

	memset (cache, -1, sizeof cache);

	cin >> w >> h;

	int bad = 0;

	fer (a, 1, w) fer (b, 1, w-a+1)
	{
		int gab =__gcd (a, b);
		int va = a/gab, vb = b/gab;
		int tmp = cnt (va, vb);
		tmp = tmp * (ll)(w+1-a-b) * 6LL % mod;
		bad += tmp; if (bad >= mod) bad -= mod;
	}

	bad = (bad + (h+1) * (ll)h % mod * (ll)(h-1) * (ll)(w+1)) % mod;

	int tot = (w+1) * (h+1);

	bad = (bad + tot * 3LL * (tot-1)) % mod;
	bad = (bad + 1LL * tot) % mod;

	pii wc = hmw (w+1);
	pii hc = hmw (h+1);

	int ans = (wc.X * (ll)(hc.X + hc.Y) + wc.Y * (ll)hc.X) % mod;
	ans = (ans + wc.Y * 1LL * hc.Y % mod * pm (3, mod-2)) % mod;

	cout << (ans-bad+mod)%mod << endl;

	{ int _; cin >> _; }
	return 0;
}
