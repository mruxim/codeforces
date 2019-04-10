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

const int maxn = 1000000 + 100;

int n, t;
int p[maxn], q;
int st[maxn], top;

inline int Abs (int x) { return x < 0 ? -x : x; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> p[i];
	cin >> t;
	rep (i, t) cin >> q, p[q-1] *= -1;

	rof (i, n, 0)
		if (p[i] < 0 || top == 0 || (p[i] != Abs(p[st[top-1]])))
			st[top++] = i;
		else
			top--, p[st[top]] = -Abs (p[st[top]]);

	cout << (top==0 ? "YES" : "NO") << endl;
	if (top==0)	
	{
		fer (i, 1, n-1) cout << p[i] << ' ';
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
