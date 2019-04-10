// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = (1<<31)-1;
const int maxn = 400 + 10;

int n;
int c[maxn];
int ans = inf;

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	rep(i, n) cin >> c[i];
	rof(i, n, 1) if(c[i-1] < ans) fer(j, i, n) {
		int x = c[i-1] - 1, y = x, z, opt = 1, cnt = 0;
		fer(k, i, j+1)
			opt += y / c[k], y %= c[k];
		z = x - y + c[j];
		rep(k, n)
			cnt += z / c[k], z %= c[k];
		if(opt < cnt)
			ans = min(ans, x - y + c[j]);
	}
	cout << (ans == inf ? -1 : ans) << endl;

	{ int _; cin >> _; }
	return 0;
}
