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
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 10000 + 100;

int n, m, p;
int a[maxn];
int b;
vector<int> dv, cnt;
vector<bool> mark;

int pm (int x, int y)
{
	int ret = 1;
	for (int tmp = x; y; y >>= 1)
	{
		if (y & 1) ret = ret * (ll)tmp % p;
		tmp = tmp*(ll)tmp % p;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	while (cin >> p)
	{
		fer (i, 1, p)
		{
			int r = 0, c = 1;
			rep (k, p-1) cout << c << ' ', c = c*i%p, r++, (k<p-2 && c == 1 ? r = 0 : 0);
			cout << " !! " << r << endl;
		}
	}


	cin >> n >> m >> p;
	rep (i, n) cin >> a[i];
	b = p-1;
	rep(i, m) { int x; cin >> x; b = __gcd (b, x); }
	rep(i, n) a[i] = pm(a[i], b);

	for(int i = 1; i*i <= p-1; i++)
		if((p-1) % i == 0) { dv.pb(i); if (i*i != (p-1)) dv.pb ((p-1)/i); }
	sort(all(dv));

	cnt.resize(sz(dv));
	rep(i, sz(dv)) {
		int tot = 0;
		rep(j, i) if (dv[i] % dv[j] == 0) tot += cnt[j];
		cnt[i] = dv[i] - tot;
	}

	mark.resize(sz(dv));
	rep(i, n) rep(j, sz(dv)) if(pm(a[i], dv[j]) == 1) {
		// cycle length a[i] == dv[j]
		rep(k, j+1) if (dv[j] % dv[k] == 0) mark[k] = true;
		break;
	}

	int ans = 0;
	rep (i, sz(dv)) if (mark[i]) ans += cnt[i];

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
