// .... .... .... !

#include <iostream>
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

const int mod = 1000000000 + 7;
const int maxn = 2000 + 100;

int powmod (int a, int b)
{
	if (b == 0) return 1;
	int x = powmod (a, b/2);
	x = x*(ll)x % mod;
	if (b&1) x = x*(ll)a % mod;
	return x;
}

int comb (int a, int b)
{
	b--;
	b += a;
	a = b - a;
	int ret = 1;
	for (int i = a + 1; i <= b; i++)
		ret = ret * (ll)i % mod * powmod (i - a, mod - 2) % mod;
	return ret;
}

int n, k;
int a[maxn], c[maxn];
int r[maxn];

int main()
{
	cin >> n >> k;
	rep (i, n) cin >> a[i];

	rep (i, n) c[i] = comb (i, k);

	rep (i, n) fer (j, i, n)
		r[j] = (r[j] + c[j-i] * (ll)a[i]) % mod;

	rep (i, n) cout << r[i] << ' ';
	cout << endl;

	{ int _; cin >> _; }
	return 0;
}
