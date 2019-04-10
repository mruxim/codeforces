// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
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
string s[maxn];
int vis[256];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> s[i];

	rep(i, n) rep(j, n) vis[(int)s[i][j]] = 1;

	if(accumulate(vis, vis+256, 0) != 2) { cout << "NO" << endl; return 0; }

	char cx = s[0][0];

	rep(i, n) rep(j, n) {
		if((i == j || i == n-j-1) && s[i][j] != cx) {
			cout << "NO" << endl; return 0;
		}
		if((i != j && i != n-j-1) && s[i][j] == cx) {
			cout << "NO" << endl; return 0;
		}
	}

	cout << "YES" << endl;

	{ return 0; }
}

