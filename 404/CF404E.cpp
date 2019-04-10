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

const int maxn = 1000000 + 100;

int n;
string s;
int a[maxn];

pii simul(int block) {
	int pos = 0;
	int rm = 0;
	rep(i, n) {
		smax(rm, pos);
		pos += a[i];
		smax(pos, block);
	}
	return {pos, rm};
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> s;
	n = sz(s);
	rep(i, n) a[i] = (s[i] == 'L' ? -1 : 1);

	if(s.back() == 'L') rep(i, n) a[i] = -a[i];

	pii tmp = simul(-1e7);

	if(tmp.X > tmp.Y) { cout << 1 << endl; return 0; }

	tmp = simul(0);

	if(tmp.X <= tmp.Y) { cout << 0 << endl; return 0; }
	
	int lo = 0, hi = 1e7;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		tmp = simul(-md);
		if(tmp.X <= tmp.Y) hi = md;
		else lo = md;
	}

	cout << hi << endl;

	{ return 0; }
}

