// .... .... .... !

#include <iostream>
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
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n, r;
int f[1000], fs;

int main()
{
	f[0] = 0, f[1] = 1;
	for (fs = 2; f[fs-1] < 1e8; fs++) f[fs] = f[fs-1] + f[fs-2];

	cin >> n >> r;
	if (n > r)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	{ int _; cin >> _; }
	return 0;
}

