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

const int maxn = 1000000 + 100;

int n, t;
ll a[maxn];
ll dv[100000];
int cnt[100000];

ll gcd (ll x, ll y) {
	while(x) {
		ll tmp = x;
		x = y % x;
		y = tmp;
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	rep (i, n) cin >> a[i];
	random_shuffle(a, a+n);
	random_shuffle(a, a+n);

	ll ans = 0;

	rep(z, min(n, 13)) {
		ll x = a[z];
		t = 0;
		for(ll i = 1; i*i <= x; i++) if (x % i == 0)
			dv[t++] = i, (i*i != x ? dv[t++] = x/i : 0);
		sort(dv, dv+t);
		memset(cnt, 0, t * sizeof(cnt[0]));
		rep(i, n) cnt[lower_bound(dv, dv+t, gcd(a[z], a[i])) - dv]++;
		rep(i, t) rep (j, i) if(dv[i] % dv[j] == 0) cnt[j] += cnt[i];
		rep(i, t) if(cnt[i]*2 >= n) ans = max(ans, dv[i]);
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
