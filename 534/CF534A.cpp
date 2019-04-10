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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	if(n == 4) a.pb(3);
	a.pb(1);
	if(n == 4) a.pb(4), a.pb(2);
	else {
		for(int i = 3; i <= n; i += 2) a.pb(i);
		for(int i = 2; i <= n; i += 2) if(abs(a.back() - i) != 1) a.pb(i);
	}

	cout << sz(a) << endl;
	for(int x: a) cout << x << ' ';
	cout << endl;

	return 0;
}

