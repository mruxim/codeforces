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

const int mod = 1000000000+7;
const int maxn = 100000 + 100;

int n;
int a[maxn];
int ra[maxn];

int f[maxn], rf[maxn];

int powmod (int a, int b)
{
	if (b == 0) return 1 % mod;
	if (b & 1) return powmod (a, b-1) * (ll)a % mod;
	int r = powmod (a, b/2);
	return r * (ll)r % mod;
}

int comb (int a, int b)
{
	return f[a] * (ll)rf[b] % mod * (ll)rf[a-b] % mod;
}

int go (int l, int r, int k, int pk)
{
	int pos = ra[k];

	if (l <= pos && pos < r) return 0;
	if (l < 0 || r > n) return 0;
	if (k == n-1) return 1;

	int nk = k+1;
	while (ra[nk] == -1) nk++;

	int emp = (pos<l ? l-pos : pos-r+1) - 1;
	if (emp > k-pk-1) return 0;

	int mul = comb (k-pk-1, emp);

	if (pos < l)
		return go (pos, pos+k+1, nk, k) * (ll)mul % mod;
	else
		return go (pos-k, pos+1, nk, k) * (ll)mul % mod;
}

int main()
{
	ios_base::sync_with_stdio (false);

	f[0] = 1;
	fer (i, 1, maxn) f[i] = f[i-1] * (ll)i % mod;
	rep (i, maxn) rf[i] = powmod (f[i], mod-2);

	cin >> n;
	rep (i, n) cin >> a[i+1], a[i+1]--;
	a[0] = n, a[n+1] = n+1; n += 2;

	memset (ra, -1, sizeof ra);
	rep (i, n) if (a[i] != -1) ra[a[i]] = i;

	int mn = 0;
	while (ra[mn] == -1) mn++;

	int ans = 0;
	int nx = mn+1;
	while (ra[nx] == -1) nx++;
	ans += go (ra[mn], ra[mn] + mn+1, nx, mn);
	if (mn != 0) ans += go (ra[mn] - mn, ra[mn]+1, nx, mn);
	ans %= mod;
	rep (i, mn-1) ans *= 2, ans %= mod;

	cout << ans % mod << endl;

	{ return 0; }
}

