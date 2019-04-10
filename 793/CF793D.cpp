// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = 1 << 28;
const int maxn = 80 + 8;

int n, K, m;
int e[maxn][maxn];
int mem[maxn][maxn][maxn];

int calc(int a, int b, int k) {
	if(k == 0) return 0;
	int &res = mem[a][b][k];
	if(res != -1) return res;
	res = inf;
	for(int i = min(a, b) + 1; i < max(a, b); i++)
		smin(res, e[b][i] + min(calc(a, i, k - 1), calc(b, i, k - 1)));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> K;

	rep(i, n+2) rep(j, n+2) e[i][j] = inf;
	rep(i, n+2) e[n+1][i] = 0;
	memset(mem, -1, sizeof mem);

	cin >> m;
	rep(i, m) { int u, v, c; cin >> u >> v >> c; smin(e[u][v], c); }

	int ans = calc(0, n+1, K);
	cout << (ans != inf ? ans : -1) << endl;

	return 0;
}

