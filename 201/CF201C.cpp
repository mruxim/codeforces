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

const int maxn = 100000 + 100;

int n;
ll a[maxn];
ll lft[maxn], rgt[maxn];
ll l[maxn], r[maxn];
int lf[maxn], rf[maxn];

int main()
{
	cin >> n;
	rep (i, n-1) cin >> a[i];

	rep (i, n)
		if (i && a[i-1] >= 2)
			lft[i] = lft[i-1] + a[i-1] / 2 * 2;
	rof (i, n, 0)
		if (i<n-1 && a[i] >= 2)
			rgt[i] = rgt[i+1] + a[i] / 2 * 2;

	rep (i, n)
		if (i && a[i-1])
			l[i] = max (l[i-1] + 1 + (a[i-1] - 1) / 2 * 2, a[i-1]>=2 ? (lft[i-1] + a[i-1]/2*2) : 0);
	rof (i, n, 0)
		if (i<n-1 && a[i])
			r[i] = max (r[i+1] + 1 + (a[i] - 1) / 2 * 2, a[i]>=2 ? (rgt[i+1] + a[i]/2*2) : 0);

	rep (i, n)
		if (i && a[i-1] % 2)
			lf[i] = lf[i-1] + 1;
	rof (i, n, 0)
		if (i<n-1 && a[i] % 2)
			rf[i] = rf[i+1] + 1;
	
	ll ans = 0;
	ll ans2 = 0;
	
	rep (i, n-1)
	{
		ans = max (ans, lft[i] + r[i]);
		ans = max (ans, rgt[i] + l[i]);
		ans = max (ans, lft[i] + rgt[i] + max (lf[i], rf[i]));


		ans2 = max (ans2, lft[i] + r[i]);
		ans2 = max (ans2, rgt[i] + l[i]);
	}
	
	cout << ans << ' ' << ans2 << endl;
	{ int _; cin >> _; }
}
