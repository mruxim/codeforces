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

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, k;
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k; k--;
	rep(i, n) cin >> a[i];

	bool same = true;
	fer(i, k, n) if(a[i] != a[n-1]) same = false;
	
	if(!same) { cout << -1 << endl; return 0; }

	bool id = -1;
	rof(i, k, 0) if(a[i] != a[k]) { id = i; break; }

	cout << id + 1 << endl;

	return 0;
}

