
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

const int maxk = 1000+10;

int n, m, k, mod;
pair<pii, int> p[maxk];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> k;
	rep (i, k) cin >> p[i].first.X >> p[i].first.Y >> p[i].second, p[i].first.X--, p[i].first.Y--;
	cin >> mod;
	if (n < m) {
		swap (n, m);
		rep (i, k) swap (p[i].first.X, p[i].first.Y);
	}
	sort (p, p+k);
	int ans = (n^m^1)&1;
	int cnt = n-1;
	rep (i, k) {
		cnt--;
		int j = i, mul = 1;
		while (j < k && p[j].first.X == p[i].first.X) mul *= p[j].second, j++;
		if (j-i == m && mul == 1) ans = 0;
		rep (z, m-(j-i)-1) ans = ans*2 >= mod ? ans*2-mod : ans*2;
		i = j-1;
	}
	cnt *= m-1;
	rep (z, cnt) ans = ans*2 >= mod ? ans*2-mod : ans*2;

	cout << ans << endl;


	{ return 0; }
}

