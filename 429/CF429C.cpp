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

const int maxn = 24 + 5;

int n;
int a[maxn], b[maxn];

void go(int p) {
	if(b[p] != 0 && b[p] != a[p]-1) return;
	if(p == 0) throw 0;
	rep(i, p) if(a[i]-1 > a[p] && a[i]-1-b[i] >= a[p]) {
		b[i] += a[p];
		go(p-1);
		b[i] -= a[p];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	sort(a, a+n, greater<int>());

	if(a[0] != n || a[n-1] != 1) { cout << "NO" << endl; return 0; }
	
	while(n && a[n-1] == 1) n--;

	try {
		go(n-1);
		cout << "NO" << endl;
	} catch(...) {
		cout << "YES" << endl;
	}

	{ return 0; }
}

