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

const int maxn = 100000 + 100;

int n, m;
int a[maxn], b[maxn];
int p[maxn];

bool mark[maxn];
int pre[maxn];
int ans[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i], a[i] = m - a[i] - 1;
	rep (i, n) cin >> b[i];
	sort (a, a+n);
	sort (b, b+n);

	rep (i, n) p[i] = (upper_bound (b, b+n, a[i]) - b + n - 1) % n;

	int k = 0;
	while (p[k] == p[(k-1+n)%n] && (a[k]-b[p[k]]+m)%m > (a[(k-1+n)%n]-b[p[k]]+m)%m) k++;

	rep (i, n) pre[i] = (i-1+n) % n;

	rep (z, n)
	{
		int t = p[k], r;
		while (mark[t]) r = pre[t], pre[t] = pre[r], t = r;
		mark[t] = 1;
		ans[z] = (5*m-1 - (a[k] - b[t])) % m;
		k = (k+1) % n;
	}

	sort (ans, ans+n);
	rep (i, n) cout << ans[n-i-1] << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
