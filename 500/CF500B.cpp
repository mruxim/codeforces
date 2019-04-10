// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300 + 100;

int n;
int p[maxn];
char s[maxn][maxn];
bool mark[maxn];
vector<int> a, b;

void dfs(int u) {
	if(mark[u]) return;
	mark[u] = true;
	a.pb(u); b.pb(p[u]);
	rep(v, n) if(s[u][v] == '1') dfs(v);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, n) if(s[i][j] == '1') s[j][i] = '1';

	rep(i, n) if(!mark[i]) {
		a.clear(); b.clear();
		dfs(i);
		sort(all(a));
		sort(all(b));
		rep(j, sz(a)) p[a[j]] = b[j];
	}

	rep(i, n) cout << p[i] << ' '; cout << endl;

	return 0;
}

