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

const int maxn = 100000 + 100;

int n;
int x[maxn];
int a, b;
int up[1000000+1000];
int dis[1000000+1000];
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> x[i];
	sort (x, x+n);
	n = unique (x, x+n) - x;
	cin >> a >> b;

	rep (i, a-b+1) up[i] = i+1;

	rep (i, n)
	{
		if (x[i] == 2) continue;
		int pos = (b + x[i] - 1) / x[i] * x[i] - b;
		while (pos <= a-b) up[pos] = pos+x[i]-1, pos += x[i];
	}

	dq.push_back (0);
	dis[0] = 0;

	fer (i, 1, a-b+1)
	{
		while (up[dq.front()] < i) dq.pop_front();
		dis[i] = dis[dq.front()] + 1;
		if (up[i] > up[dq.back()]) dq.push_back (i);
	}

	cout << dis[a-b] << endl;

	{ int _; cin >> _; return 0; }
}
