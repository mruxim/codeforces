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

const int maxn = 4000 + 100;

const int eps = 1e-12;

int n, k;

int s[maxn][maxn];
double w[maxn][maxn];

double dis[maxn];
int mnt[maxn];

int go (double add)
{
	rep (i, n+1) dis[i] = 1e12;
	dis[0] = 0, mnt[0] = 0;
	
	rep (i, n) fer (j, i+1, n+1)
	{
		double ndis = dis[i] + w[i][j] + add;
		if (ndis+eps < dis[j]) dis[j] = ndis, mnt[j] = mnt[i]+1;
		else if (ndis-eps < dis[j]) mnt[j] = min (mnt[j], mnt[i]+1);
	}
	return mnt[n];
}

int main()
{
	cin >> n >> k;
	rep (i, n) rep (j, n) s[i+1][j+1] = (getchar(), getchar()) - '0';
	rep (i, n) rep (j, n) s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + s[i+1][j+1];

	rep (i, n) fer (j, i+1, n+1) w[i][j] = s[j][j] - s[i][j] - s[j][i] + s[i][i] + (rand() % 400) / 100000.0;

	int ans = 1<<30;

	double lo = -1e8, hi = 1e8;
	rep (i, 80)
	{
		double md = (lo + hi) / 2;
		int tmp = go (md);

		if (tmp <= k) ans = min (ans, ((int)(dis[n] - md*tmp + 0.001))/2);

		if (tmp < k) hi = md;
		else lo = md;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
