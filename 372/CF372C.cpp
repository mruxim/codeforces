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

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 150000 + 100;
const int maxm = 300 + 10;
const ll inf = 1LL << 60;

int n, m, d;
int a[maxm], b[maxm], t[maxm];
ll dp[maxn];
pair<ll, int> f[maxn];
int nx[maxn];

void csort (pair<ll, int> a[], int n)
{
	static int c[1<<16];
	static pair<ll, int> b[maxn];
	rep (i, n) a[i].X += 1LL << 40;
	ll v = (1 << 16) - 1;
	memset (c, 0, sizeof c);
	for (int i = 0; i < n; i++) c[a[i].X & v]++;
	for (int i = 1; i < 1<<16; i++) c[i] += c[i-1];
	for (int i = n; i-- > 0; ) b[--c[a[i].X & v]] = a[i];
	memset (c, 0, sizeof c);
	for (int i = 0; i < n; i++) c[b[i].X >> 16 & v]++;
	for (int i = 1; i < 1<<16; i++) c[i] += c[i-1];
	for (int i = n; i-- > 0; ) a[--c[b[i].X >> 16 & v]] = b[i];
	memset (c, 0, sizeof c);
	for (int i = 0; i < n; i++) c[a[i].X >> 32 & v]++;
	for (int i = 1; i < 1<<16; i++) c[i] += c[i-1];
	for (int i = n; i-- > 0; ) b[--c[a[i].X >> 32 & v]] = a[i];
	memset (c, 0, sizeof c);
	for (int i = 0; i < n; i++) c[b[i].X >> 48 & v]++;
	for (int i = 1; i < 1<<16; i++) c[i] += c[i-1];
	for (int i = n; i-- > 0; ) a[--c[b[i].X >> 48 & v]] = b[i];
	rep (i, n) a[i].X -= 1LL << 40;
}


int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> d;
	rep (i, m) cin >> a[i] >> b[i] >> t[i], a[i]--;

	rep (z, m-1)
	{
		rep (i, n) dp[i] += b[z] - abs (a[z] - i);
		int md = (int)min ((ll)n, d * (ll)(t[z+1] - t[z]));

		rep (i, n) f[i].X = dp[i], f[i].Y = i;
		csort (f, n);
		reverse (f, f+n);
		fill (dp, dp+n, -inf);

		rep (i, n) nx[i] = i+1;
		int dn = 0;
		rep (i, n)
		{
			int L = max (f[i].Y - md, 0), R = min (f[i].Y + md + 1, n);
			ll V = f[i].X;
			for (int pos = L, tmp; pos < R; tmp = pos, pos = nx[pos], nx[tmp] = R)
				if (dp[pos] == -inf)
					dp[pos] = V, dn++;
			if (dn == n) break;
		}
	}
	rep (i, n) dp[i] += b[m-1] - abs (a[m-1] - i);

	cout << *max_element (dp, dp+n) << endl;

	{ int _; cin >> _; return 0; }
}
