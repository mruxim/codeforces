// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
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

const int mod = 1000000000+7;

const int maxk = 1000000 + 100;

int k, w;
int s[maxk], p[maxk];
int f[maxk], rf[maxk];

int pw (int a, int n)
{
	ll r = 1, c = (ll)a;
	for (; n; n >>= 1, c = c * c % mod)
		if (n & 1)
			r = r * c % mod;
	return (int)r;
}

int calc (int k, int w)
{
	int ans = 0;
	int r = pw (k, 2*w - min (k+w, 2*w-1) - 1);
	rof (i, min (k+w, 2*w-1), ::w+1)
	{
		int t = i-w+1;
		ans = (ans + s[t] * (ll)s[t] % mod * (ll)r) % mod;
		r = r * (ll)k % mod;
	}
	fer (i, 2*w-1, k+w)
	{
		int t = i-2*w+2;
		int v = f[k-t] * (ll)rf[k-t-w+1] % mod;
		ans = (ans + s[t] * (ll)v % mod * (ll)v) % mod;
	}
	return ans;
}

int main()
{
	cin >> k >> w;

	s[0] = 1; fer (i, 1, k+1) s[i] = s[i-1] * (ll)(k-i+1) % mod;
	p[0] = 1; fer (i, 1, k+1) p[i] = p[i-1] * (ll)k % mod;
	f[0] = 1; fer (i, 1, k+1) f[i] = f[i-1] * (ll)i % mod;
	rep (i, k+1) rf[i] = pw (f[i], mod-2);

	cout << (calc (k, w+1) - calc (k, w) + mod) % mod << endl;

	{ int _; cin >> _; }
}
