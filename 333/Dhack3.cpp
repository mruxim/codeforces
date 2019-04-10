// .... .... .....!
// P..... C.....!

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int main()
{
//	ios::sync_with_stdio (false);

	int n, m;
	n = 1000;
	m = 1000;

	printf ("%d %d\n", n, m);
	rep (i, n)
	{
		rep (j, m)
		{
			if ((i==5&&j==5) || (i==5&&j==10) || (i==10&&j==5) || (i==10&&j==10))
				printf ("%d", 1000000000);
			else
				printf ("%d",1000000000);
			if (j < m-1)
				printf (" ");
		}
		printf ("\n");
	}

	{ int _; cin >> _; return 0; }
}
