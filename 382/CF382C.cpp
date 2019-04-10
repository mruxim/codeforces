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

const int maxn = 100000 + 100;

int n;
int a[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	sort (a, a+n);

	if (n == 1) { cout << -1 << endl; return 0; }
	if (n == 2)
	{
		set<int> s;
		s.insert (2*a[1]-a[0]);
		s.insert (2*a[0]-a[1]);
		if (a[0]%2 == a[1]%2) s.insert ((a[0]+a[1])/2);
		cout << sz(s) << endl;
		for (int x: s) cout << x << ' '; cout << endl;
		return 0;
	}

	int diff = 1e9;
	rep (i, n-1) smin (diff, a[i+1]-a[i]);
	int need = 0, pos = 0;
	rep (i, n-1) if (a[i]+diff < a[i+1])
		pos = a[i]+diff, need += (a[i]+2*diff == a[i+1] ? 1 : 2);

	if (need == 0)
	{
		if (diff == 0) cout << 1 << endl << a[0] << endl;
		else cout << 2 << endl << a[0]-diff << ' ' << a[n-1]+diff << endl;
	}
	else if (need == 1)
		cout << 1 << endl << pos << endl;
	else
		cout << 0 << endl;

	{ return 0; }
}

