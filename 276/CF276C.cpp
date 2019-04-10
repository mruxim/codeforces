// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

const int maxn = 200000 + 100;

int n, q;
int p[maxn], c[maxn];
pii a[2*maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> q;
	rep (i, n) cin >> p[i];
	sort (p, p+n);
	rep (i, q) cin >> a[2*i].first >> a[2*i+1].first, a[2*i].first--, a[2*i].second = 1, a[2*i+1].second = -1;
	sort (a, a+2*q);

	int pos = 0, cnt = 0;
	rep (i, n)
	{
		while (pos<2*q && a[pos].first <= i) cnt += a[pos++].second;
		c[i] = cnt;
	}
	sort (c, c+n);
	ll ans = 0;
	rep (i, n)
		ans += c[i]*(ll)p[i];
	cout << ans << endl;
	{ int _; cin >> _; return 0; }
}
