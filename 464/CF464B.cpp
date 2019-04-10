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

int p[8][3], q[8][3];
int a[6*5/2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, 8) rep(j, 3) cin >> p[i][j];

	rep(z, 6*6*6*6*6*6*6*6) {
		int t = z;
		rep(i, 8) {
			int r = t % 6; t /= 6;
			if(r == 0) q[i][0] = p[i][0], q[i][1] = p[i][1], q[i][2] = p[i][2];
			if(r == 1) q[i][0] = p[i][0], q[i][1] = p[i][2], q[i][2] = p[i][1];
			if(r == 2) q[i][0] = p[i][1], q[i][1] = p[i][0], q[i][2] = p[i][2];
			if(r == 3) q[i][0] = p[i][1], q[i][1] = p[i][2], q[i][2] = p[i][0];
			if(r == 4) q[i][0] = p[i][2], q[i][1] = p[i][0], q[i][2] = p[i][1];
			if(r == 5) q[i][0] = p[i][2], q[i][1] = p[i][1], q[i][2] = p[i][0];
		}
		
		int c = 0;
		rep(i, 6) rep(j, i) a[c++] 
	}

	return 0;
}

