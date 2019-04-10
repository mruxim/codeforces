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

const int maxn = 1000 + 100;

int n, m;
char s[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> s[i];

	int mini = 1e9, maxi = -1e9, minj = 1e9, maxj = -1e9;

	rep(i, n) rep(j, n) if(s[i][j] == '#')
		smin(mini, i), smax(maxi, i),
		smin(minj, j), smax(maxj, j);

	if(mini == (int)1e9) { cout << "NO" << endl; return 0; }

	if(s[mini][minj] == '#')

	{ return 0; }
}

