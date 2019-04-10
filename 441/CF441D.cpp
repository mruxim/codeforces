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

int n, m;
int p[3333];
bool mark[3333];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> p[i], p[i]--;
	cin >> m;

	int cm = n;
	rep(i, n) if(!mark[i]) {
		cm--;
		for(int x = i; !mark[x]; mark[x] = 1, x = p[x]);
	}

	cout << abs(cm - m) << endl;
	while(cm != m) {
		if(cm > m) {
			memset(mark, 0, sizeof mark);
			rep(i, n) if(!mark[i]) {
				int x = i;
				int cnt = 0;
				int y = n+10;
				while(!mark[x]) {
					mark[x] = 1, x = p[x], cnt++;
					if(x != i) smin(y, x);
				}
				if(cnt > 1) {
					swap(p[y], p[i]);
					cm--;
					cout << i+1 << ' ' << y+1 << ' ';
					break;
				}
			}
		} else {
			memset(mark, 0, sizeof mark);
			int x = 0, y = 0;
			for(x = 0; !mark[x]; mark[x] = 1, x = p[x]);
			rep(i, n) if(!mark[i]) { y = i; break; }
			x = 0;
			cout << x+1 << ' ' << y+1 << ' ';
			swap(p[x], p[y]);
			cm++;
		}
	}

	{ return 0; }
}

