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

const int maxn = 100000 + 100;

int n;
pii s[maxn];
int a[maxn], b[maxn];

int main() {
	ios::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> s[i].X, s[i].Y = i;
	sort(s, s+n);

	rep(i, n) {
		if(i < (n+2)/3)
			a[s[i].Y] = 0, b[s[i].Y] = s[i].X;
		else if (i < (n+2)/3+(n/3))
			a[s[i].Y] = s[i].X, b[s[i].Y] = 0;
		else
			a[s[i].Y] = n - i - 1, b[s[i].Y] = s[i].X - a[s[i].Y];
	}

	cout << "YES" << endl;
	rep(i, n) cout << a[i] << ' '; cout << endl;
	rep(i, n) cout << b[i] << ' '; cout << endl;

	{ int _; cin >> _; return 0; }
}
