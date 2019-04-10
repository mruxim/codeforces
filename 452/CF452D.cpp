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

int k;
int n1, n2, n3;
int t1, t2, t3;
multiset<int> e1, e2, e3;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;

	rep(i, n1) e1.insert(0);
	rep(i, n2) e2.insert(0);
	rep(i, n3) e3.insert(0);

	while(k--) {
		int cur = max(*e1.begin(), max((*e2.begin()) - t1, (*e3.begin()) - t1 - t2));
		
		e1.erase(e1.begin());
		e1.insert(cur + t1);
		
		e2.erase(e2.begin());
		e2.insert(cur + t1 + t2);
		
		e3.erase(e3.begin());
		e3.insert(cur + t1 + t2 + t3);
	}

	cout << *e3.rbegin() << endl;

	{ return 0; }
}

