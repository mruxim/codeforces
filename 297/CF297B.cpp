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

int n, m, k;
int a[maxn], b[maxn];
bool yes;

int main() {
	ios::sync_with_stdio (false);

	cin >> n >> m >> k;
	rep(i, n) cin >> a[i]; sort(a, a+n);
	rep(i, m) cin >> b[i]; sort(b, b+m);
	if(n > m) yes = true;
	int x = n-1, y = m-1;
	while(x >= 0) {
		if(a[x] > b[y]) yes = true;
		x--, y--;
	}
	cout << (yes ? "YES" : "NO") << endl;

	{ int _; cin >> _; return 0; }
}
