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

const int lose = -1e9 - 2532357;
const int draw = -1e9 - 5343624;

int solve (int x, int a, int b) // assump. a <= b
{
	if (a <= x && x <= b) return x;

	int sgn = 1;

	if (x < 0)
	{
		swap (a, b);
		a = -a, b = -b, x = -x;
		sgn = -1;
	}

	if (x < a) return draw;
	if (a <= 0) return draw;
	int sum = a+b;

	if (x % sum == 0) return a > 0 ? lose : draw;
	ll r = x % sum, l = sum - r;

	if (a <= r && r <= b) return sgn * r;
	if (a <= -l && -l <= b) return sgn * (-l);

	assert (0 < a);

	int mv = x - (x-a) / sum * sum;

	if (mv <= b) return sgn * mv;

	return draw;
}

int main()
{
	ios_base::sync_with_stdio (false);

	int x1, x2, x;
	int a, b;

	cin >> x1 >> x2 >> a >> b;
	x = x2-x1;

	int p = solve (x, a, b);

	if (p == lose) cout << "SECOND" << endl;
	else if (p == draw) cout << "DRAW" << endl;
	else cout << "FIRST" << endl << x1+p << endl;

	{ int _; cin >> _; return 0; }
}
