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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 * 1000 + 100;

int n, l, t;
int h;
ll a[3*maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> l >> t;
	h = t / l, t %= l;
	rep (i, n) cin >> a[i], a[n+i] = l + a[i], a[n+n+i] = l + l + a[i];

	ll sum = 0;

	rep (i, n)
	{
		int pos;

		pos = upper_bound (a, a+3*n, a[i] + 2*t) - a;
		int cnt1 = pos - i - 1; if (pos > n+i) cnt1--;

		pos = lower_bound (a, a+3*n, a[i]+l+l - 2*t) - a;
		int cnt2 = n+n+i - pos; if (pos <= n+i) cnt2--;

		sum += cnt1 + cnt2;
	}

	cout << fixed << setprecision (8) << (sum / 4.0 + h * (ll)n * (ll)(n-1)) / 2.0 << endl;

	{ int _; cin >> _; return 0; }
}
