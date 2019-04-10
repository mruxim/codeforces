// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
bool w[1111111];

int main()
{
	ios::sync_with_stdio (false);
	w[0] = w[1] = w[2] = false;
	fer (i, 3, 111111)
	{
		w[i] = !(w[i/3] && w[i-i/3]);
		if (w[i] != w[i-1])
			cerr << i << ' ' << (w[i] ? "W" : "L") << endl;
	}
	{ int _; cin >> _; return 0; }
}
