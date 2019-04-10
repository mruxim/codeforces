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

int n, m;
vector<int> adj[maxn];
int indeg[maxn];
int ss, tt;
int dis[maxn];
deque<pii> deq;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v; u--, v--;
		adj[v].pb(u);
		indeg[u]++;
	}
	cin >> ss >> tt;
	ss--, tt--;

	memset(dis, -1, sizeof dis);

	deq.push_back(pii (tt, 0));

	while(!deq.empty()) {
		int v = deq.front().X, expdis = deq.front().Y;
		deq.pop_front();
		if(dis[v] != -1) continue;
		dis[v] = expdis;

		for(int u: adj[v]) {
			indeg[u]--;
			if(indeg[u] == 0)
				deq.push_front(pii(u, dis[v]));
			else
				deq.push_back(pii(u, dis[v] + 1));
		}
	}

	cout << dis[ss] << endl;

	{ int _; cin >> _; return 0; }
}
