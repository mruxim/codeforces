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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m, k;
ll a[maxn];
int l[maxn], r[maxn], d[maxn];
int t[maxn], v[maxn]; // k
ll c[maxn], f[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m >> k;
	rep (i, n) cin >> a[i];
	rep (i, m) cin >> l[i] >> r[i] >> d[i], l[i]--;
	rep (i, k) { int x, y; cin >> x >> y; x--; t[x]++, t[y]--; }

	v[0] = t[0]; fer (i, 1, m) v[i] = v[i-1] + t[i];

	rep (i, m) c[l[i]] += d[i] * (ll)v[i], c[r[i]] -= d[i] * (ll)v[i];

	f[0] = c[0]; fer (i, 1, n) f[i] = f[i-1] + c[i];

	rep (i, n) cout << a[i] + f[i] << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
