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

const int maxn = 2*100000 + 1000;

int n, m;
int a[maxn], c[maxn], p[maxn];

int nx (int k) {
	if(k >= n || c[k] < a[k]) return k;
	return p[k] = nxt(p[k]);
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> a[i], p[i] = i+1;
	cin >> m;
	rep(z, m) {
		int t; cin >> t;
		if(t == 1) {
			int k, x; cin >> k >> x; k--;
			while(k < n && x) {
				int h = min(x, a[k] - c[k]);
				c[k] += h; x -= h;
				k = nxt(k);
			}
		} else {
			int k; cin >> k; k--;
			cout << c[k] << endl;
		}
	}

	{ return 0; }
}

