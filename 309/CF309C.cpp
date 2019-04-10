// .... .... .... !

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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 * 1000 + 100;

int n, m;
int a[32], b[32][maxn], len[32];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) { int x; cin >> x; rep (i, 30) a[i] += x % 2, x /= 2; }
	rep (i, m) { int x; cin >> x; b[x][len[x]++] = 1; }

	int r = 0;
	rep (i, 30)
	{
		while (a[i] && len[i])
		{
			r += b[i][--len[i]];
			a[i]--;
		}
		int p = len[i+1] = len[i+1] + (len[i] + 1) / 2;
		while (len[i])
		{
			int v = b[i][--len[i]];
			if (len[i]) v += b[i][--len[i]];
			b[i+1][--p] = v;	
		}	
	}

	cout << r << endl;

	{ int _; cin >> _; return 0; }
}

