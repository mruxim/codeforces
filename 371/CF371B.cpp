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

int main()
{
	ios_base::sync_with_stdio (false);

	int a, b;
	cin >> a >> b;
	int g = __gcd (a, b);
	a /= g, b /= g;

	int ans = 0;
	while (a % 2 == 0) a /= 2, ans++;
	while (a % 3 == 0) a /= 3, ans++;
	while (a % 5 == 0) a /= 5, ans++;
	while (b % 2 == 0) b /= 2, ans++;
	while (b % 3 == 0) b /= 3, ans++;
	while (b % 5 == 0) b /= 5, ans++;

	cout << ((a>1 || b>1) ? -1 : ans) << endl;

	{ return 0; }
}

