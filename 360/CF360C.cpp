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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;
const int mod = 1000000000 + 7;

int n, K;
string s;
int d[maxn][maxn];
int p[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> K;
	cin >> s;

	d[n][0] = 1;
	rof (i, n, 0) rep (k, K+1)
	{
		int cur = 0;
		bool fin = true;
		fer (j, i, n+1)
		{
			cur = (j-i+1) * (n-j);
			if (k < cur) { fin = false; break; }
			if (j == n && k==0) { d[i][k]++; }
			if (k >= cur) d[i][k] = (d[i][k] + ('z' - s[j]) * (ll)d[j+1][k-cur]) % mod;
		}
		if (!fin)
		{
			cur = 0;
			rof (j, n+1, i)
			{
				cur = (j-i+1) * (n-j);
				if (k < cur) { fin = false; break; }
				if (j == n && k==0) { d[i][k]++; }
				if (k >= cur) d[i][k] = (d[i][k] + ('z' - s[j]) * (ll)d[j+1][k-cur]) % mod;
			}
		}

		p[i][k] = (p[i+1][k] + (s[i] - 'a') * (ll)d[i+1][k]) % mod;
		d[i][k] = (d[i][k] + p[i][k]) % mod;

//		cerr << i << ' ' << k << ' ' << d[i][k] << endl;
	}

	cout << d[0][K] << endl;

	{ int _; cin >> _; return 0; }
}
