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

const int maxn = 100000 + 100;

int n, a, b;
int p[maxn];
map<int, int> pos;
vector<int> adj[maxn];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> a >> b;
	rep(i, n) cin >> p[i], pos[p[i]] = i;

	rep(i, n) {
		if(pos.find(a - p[i]) != pos.end()) {
			adj[i].pb(pos[a - p[i]]);
			if(p[i] != a - p[i]) adj[pos[a - p[i]]].pb(i);
		}
		if(pos.find(b - p[i]) != pos.end()) {
			adj[i].pb(pos[b - p[i]]);
			if(p[i] != b - p[i]) adj[pos[b - p[i]]].pb(i);
		}
	}

	
	if(count(mark, mark+n, 1) == n) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		rep(i, n) cout << mark[i] << ' ';
		cout << endl;
	}

	return 0;
}

