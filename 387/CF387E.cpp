
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

const int maxn = 1000000 + 100;

int n, k;
int p[maxn], rp[maxn];
bool rem[maxn];
int b[maxn];
int f[maxn], f2[maxn];

void add (int x) { for (x++; x < maxn; x += x&-x) f[x]++; }
int get (int x) { int ret = 0; for (; x; x -= x&-x) ret += f[x]; return ret; }
void add2 (int x) { for (x++; x < maxn; x += x&-x) f2[x]++; }
int get2 (int x) { int ret = 0; for (; x; x -= x&-x) ret += f2[x]; return ret; }

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> p[i], rp[p[i]] = i;
	rep (i, k) { int x; cin >> x; rem[rp[x]] = true; }
	k = 0; rep (i, n) if (!rem[i]) b[k++] = p[i];

	sort (b, b+k);
	int id = 1;
	ll ans = 0;
	rep (i, k) {
		for (; id < b[i]; id++) if (i==0 || id != b[i-1]) add (rp[id]); else add2 (rp[id]);
		int pos = rp[b[i]];
		int cur = get (pos);
		int l, r;
		{
			int lo = -1, hi = pos;
			while (hi-lo > 1) {
				int md = (lo+hi) / 2;
				if (get (md) != cur) lo = md;
				else hi = md;
			}
			l = hi;
		}
		{
			int lo = pos, hi = n+1;
			while (hi-lo > 1) {
				int md = (lo+hi) / 2;
				if (get (md) != cur) hi = md;
				else lo = md;
			}
			r = lo;
		}
		ans += (r-l) - (get2 (r) - get2 (l));
	}

	cout << ans << endl;

	{ return 0; }
}

