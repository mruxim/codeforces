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

vector<int> func(int n) {
	if(n == 1) return vector<int>({1});
	if(n == 2) return vector<int>({3, 4});
	vector<int> v(n, 1);
	if(n % 2)
		v.front() = 2, v.back() = (n + 1) / 2;
	else
		v.back() = (n - 2) / 2;
	return v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a = func(n), b = func(m);
	rep(i, n) {
		rep(j, m) cout << a[i] * b[j] << ' ';
		cout << endl;
	}

	{ return 0; }
}

