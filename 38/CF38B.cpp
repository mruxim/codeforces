
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

bool f[55][55];

int main()
{
	ios_base::sync_with_stdio (false);

	char ch; int x, y;
	cin >> ch >> x; x--; y = ch - 'a'; x+=20, y+=20;

	fer (i, 20, 28) f[x][i] = f[i][y] = 1;
	fer (i, -2, 3) fer (j, -2, 3) if (i*i+j*j==5) f[x+i][y+j] = 1;

	cin >> ch >> x; x--; y = ch - 'a'; x+=20, y+=20; f[x][y] = 1;
	fer (i, -2, 3) fer (j, -2, 3) if (i*i+j*j==5) f[x+i][y+j] = 1;

	int ans = 0;
	fer (i, 20, 28) fer (j, 20, 28) ans += f[i][j] == 0;

	cout << ans << endl;

	{ return 0; }
}

