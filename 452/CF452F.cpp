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

const int maxn = 300000 + 100;
const int ctv = 100;

int n;
int a[maxn], p[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i], a[i]--, p[a[i]] = i;

	rep(i, n) fer(j, i+1, min(n, i+ctv)) {
		int x;
		x = 2*a[i] - a[j];
		if(0 <= x && x < n && p[x] < i) { cout << "YES" << endl; return 0; }
		x = 2*a[j] - a[i];
		if(0 <= x && x < n && j < p[x]) { cout << "YES" << endl; return 0; }
		x = 2*j - i;
		if(0 <= x && x < n && ((p[i]<p[j] && p[j]<p[x]) || (p[x]<p[j] && p[j]<p[i]))) { cout << "YES" << endl; return 0; }
		x = 2*i - j;
		if(0 <= x && x < n && ((p[j]<p[i] && p[i]<p[x]) || (p[x]<p[i] && p[i]<p[j]))) { cout << "YES" << endl; return 0; }
	}
	cout << "NO" << endl;

	{ return 0; }
}

