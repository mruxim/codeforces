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

const int maxn = 2000 + 100;

int n, m, k;
int _a[4*maxn], *a = _a + 2*maxn;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	rep(i, n) {
		string str;
		cin >> str;
		rep(j, m)
			if(str[j] == 'R')
				a[j+i]++;
			else if(str[j] == 'L')
				a[j-i]++;
			else if(str[j] == 'U' && i % 2 == 0)
				a[j]++;
	}

	rep(i, m) cout << a[i] << ' ';
	cout << endl;

	{ return 0; }
}

