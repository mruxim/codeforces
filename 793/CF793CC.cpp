// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

#define y0 y000
#define y1 y111

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
int x0, y0, x1, y1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	cin >> x0 >> y0 >> x1 >> y1;

	if(x0 > x1) swap(x0, x1);
	if(y0 > y1) swap(y0, y1);

	return 0;
}

