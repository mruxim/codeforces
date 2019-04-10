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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const string r[2] = {"Daenerys", "Stannis"};

int n, k;
int c[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) {
		int x; cin >> x; c[x % 2]++;
	}

	int p = n - k;
	if(p == 0) { 
		cout << r[c[1] % 2] << endl;
	} else if(p % 2 == 0) {
		if(c[0] <= p/2) cout << r[k % 2] << endl;
		else if(c[1] <= p/2) cout << r[0] << endl;
		else cout << r[0] << endl;
	} else {
		if(c[1] <= p/2) cout << r[0] << endl;
		else if(k % 2 == 1 && c[0] <= p/2+1) cout << r[k % 2] << endl;
		else if(k % 2 == 0 && c[0] <= p/2) cout << r[k % 2] << endl;
		else cout << r[1] << endl;
	}

	return 0;
}

