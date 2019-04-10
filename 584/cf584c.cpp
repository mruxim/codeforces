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

int n, t;
string a, b, c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> t;
	cin >> a >> b;

	c = string(n, 'a');
	int df = 0;
	rep(i, n) {
		if(a[i] != b[i]) c[i] = (df % 2 ? a[i] : b[i]), df++;
		else c[i] = a[i];
	}

	if(df > 2*t) cout << -1 << endl;
	else {
		rep(i, n) if(a[i] == b[i] && df+2 <= 2*t)
			c[i] = (a[i] == 'a' ? 'b' : 'a'), df += 2;
#define F(x, y) (('a' != x && 'a' != y) ? 'a' : ('b' != x && 'b' != y) ? 'b' : 'c')
		rof(i, n, 0) if(a[i] != b[i] && df < 2*t) { c[i] = F(a[i], b[i]); df++; }
		cout << c << endl;
	}

	return 0;
}

