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

const int maxl = 500000 + 10;
const int maxn = 10 + 1;
const int maxlg = 17;

void suffar(char *s, int len, int p[maxlg][maxl]) {
	static pair<pii, int> tmp[maxl];
	rep(i, len) p[0][i] = s[i];
	fer(r, 1, maxlg) {
		rep(i, len) tmp[i] = {{p[r-1][i], i+(1<<r)/2 < len ? p[r-1][i+(1<<r)/2]}, i};
		sort(tmp, tmp + len);
		rep(i, len) p[r][tmp[i].Y] = (i && tmp[i-1].X == tmp[i].X ? p[r][tmp[i-1].Y] : i);
	}
}

char s[maxl];
int n;
char t[maxn][maxl];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	{ return 0; }
}

