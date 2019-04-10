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

int a[6];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, 6) cin >> a[i];
	sort(a, a+6);
	if(a[0] == a[3]) cout << (a[4] == a[5] ? "Elephant" : "Bear") << endl;
	else if(a[1] == a[4]) cout << "Bear" << endl;
	else if(a[2] == a[5]) cout << (a[0] == a[1] ? "Elephant" : "Bear") << endl;
	else cout << "Alien" << endl;

	return 0;
}

