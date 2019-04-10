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

const int mod = 1000000007;
const int maxn = 100000 + 100;
const int N = 1000 * 1000;

int n;
int a[maxn];

int f[N + 100];
int t[N + 100];

void add (int p, int x) { for (p++; p <= N; p += p & -p) f[p] = (f[p] + x >= mod ? f[p] + x - mod : f[p] + x); }
int get (int p) { ll ret = 0; for (p++; p; p -= p & -p) ret += f[p]; return ret % mod; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];

	ll ans = 0;

	rep (i, n)
	{
		ll r = get (a[i]) + 1;

		r *= a[i]; r %= mod;

		int tmp = t[a[i]];
		t[a[i]] = r;
		r = (r - tmp + mod) % mod;

		ans += r; ans %= mod;

		add (a[i], r);
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
