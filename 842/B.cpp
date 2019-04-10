// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int r, d;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> r >> d;
	cin >> n;

	int cnt = 0;
	rep(i, n) {
		int x, y, ri;
		cin >> x >> y >> ri;
		if(2 * ri <= d && x * x + y * y >= (r - d + ri) * (r - d + ri) && x * x + y * y <= (r - ri) * (r - ri))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}

