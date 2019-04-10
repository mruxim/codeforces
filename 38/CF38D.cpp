
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

const int maxn = 100 + 10;

int n;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
int z[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if (x1[i] > x2[i]) swap (x1[i], x2[i]);
		if (y1[i] > y2[i]) swap (y1[i], y2[i]);
		z[i] = x2[i]-x1[i];
		z[i] *= z[i]*z[i];
	}

	int r;
	for (r = 1; r < n; r++)
	{
		bool ok = true;
		rep (i, r)
		{
			int sum, den;
			sum = 0, den = 0;
			fer (j, i+1, r+1) sum += z[j] * (x1[j]+x2[j]), den += z[j];
			if (!(2*x1[i]*den <= sum && sum <= 2*x2[i]*den)) ok = false;
			sum = 0, den = 0;
			fer (j, i+1, r+1) sum += z[j] * (y1[j]+y2[j]), den += z[j];
			if (!(2*y1[i]*den <= sum && sum <= 2*y2[i]*den)) ok = false;
		}
		if (!ok) break;
	}

	cout << r << endl;

	{ return 0; }
}

