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

const int maxn = 3*100000 + 1000;

int n, k;
pii p[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> p[i].X, p[i].Y = i;
	cin >> k;
	sort (p, p+n);

	ll sumx = 0, sumd = 0;
	int c = 0;
	ll best = 1LL<<62; int pos = -1;
	rep (i, n+1)
	{
		if (c == k && sumd < best) best = sumd, pos = i;
		if (i-k >= 0) sumx -= p[i-k].X, c--, sumd -= sumx - p[i-k].X*(ll)c;
		if (i < n) sumd += p[i].X*(ll)c - sumx, sumx += p[i].X, c++;
	}

	rep (i, k) cout << p[pos-i-1].Y+1 << ' '; cout << endl;

	{ return 0; }
}

