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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = 1 << 28;
const int maxn = 50 + 5;

int n, m;
string s[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> s[i];

	int ans = inf;

	rep(i, n) rep(j, n) rep(k, n) {
		if(i == j || i == k || j == k) continue;
		int idis = m, jdis = m, kdis = m;
		rep(p, m) if(isdigit(s[i][p])) smin(idis, min(p, m-p));
		rep(p, m) if(islower(s[j][p])) smin(jdis, min(p, m-p));
		rep(p, m) if(s[k][p] == '&' || s[k][p] == '*' || s[k][p] == '#') smin(kdis, min(p, m-p));
		if(idis < m && jdis < m && kdis < m)
			smin(ans, idis + jdis + kdis);
	}

	cout << ans << endl;

	return 0;
}

