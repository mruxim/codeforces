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

const int maxn = 300000 + 100;

int n, m;
vector <int> adj[maxn];
int g[maxn];
int s[2*maxn], h, t;


int cnt (int x) {
	int ret = 0;
	for(int y: adj[x])
		if(g[x] == g[y])
			ret++;
	return ret;
}

int enemy (int x) {
	int ret = -1;
	for(int y: adj[x])
		if(g[x] != g[y])
			ret = y;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	rep (i, n) s[t++] = i;
	while (h < t) {
		int v = s[h++];
		if(cnt(v) < 2) continue;
		int u = enemy(v);
		g[v] ^= 1;
		if(cnt(u) > 1) s[t++] = u;
	}

	rep (i, n) cout << g[i];
	cout << endl;

	{ int _; cin >> _; return 0; }
}
