// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int main()
{
	ios::sync_with_stdio (false);
	int x, y, z;
	int X, Y, Z;
	int a1, a2, a3, a4, a5, a6;

	cin >> x >> y >> z;
	cin >> X >> Y >> Z;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

	int s = 0;
	if (y < 0) s += a1;
	if (y > Y) s += a2;
	if (z < 0) s += a3;
	if (z > Z) s += a4;
	if (x < 0) s += a5;
	if (x > X) s += a6;

	cout << s << endl;

	{ int _; cin >> _; }
	return 0;
}
