// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxm = 300000 + 100;
const int maxl = 20;

int m;
int dep[maxm];
int par[maxm][maxl];
int x, y, xs, ys, d;

void setpar(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	fer(i, 1, maxl) par[u][i] = par[par[u][i-1]][i-1];
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	rof(i, maxl, 0) if(dep[u] <= dep[par[v][i]]) v = par[v][i];
	if(u == v) return u;
	rof(i, maxl, 0) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

int kpar(int u, int k) {
}

int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> m;
	fer(i, 1, m+1) {
		int p; cin >> p; p--;
		setpar(i, p);
		
		if(i == 1) {
			x = 0, y = 1, xs = 1, ys = 1, d = 1;
			cout << 2 << endl;
			continue;
		}

		int dx = dis(i, x), dy = dis(i, y);

		if(dx < d && dy < d) continue;
		if(dx == d && dy == d) { xs++, ys++; continue; }
		if(dx > dy) swap(x, y), swap(xs, ys);
		if(dy == d) { xs++; continue; }
		if(dx > d) { ys--; x = i; xs = 1; d = dx; continue; } // dx == dy == d + 1 && d % 2 == 0
		if(dy > d)
	}

	return 0;
}

