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

int n;
int p[100000+555];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	if (n % 4 >= 2) cout << -1 << endl;
	else
	{
		for (int i = 0; i < n/2; i += 2)
		{
			cerr << i << endl;
			p[i] = i+1;
			p[i+1] = n-i-1;
			p[n-i-1] = n-i-2;
			p[n-i-2] = i;
		}
		if (n%2)
			p[n/2] = n/2;
		rep (i, n)
			cout << p[i]+1 << ' ';
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
