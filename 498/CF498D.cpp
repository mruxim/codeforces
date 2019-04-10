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

const int maxn = 100000 + 1000;
const int ctv = 162;
const int lcm = 60;

int n, q;
int a[maxn];
int p[maxn/ctv][lcm];

inline int nextInt() {
	register char ch;
	register int res;
	while((ch = getchar()) < '0');
	for(res = ch - '0'; (ch = getchar()) >= '0'; res = res * 10 + ch - '0');
	return res;
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0);

	fill(a, a+maxn, 1);

	cin >> n;
	rep(i, n) a[i] = nextInt();
//	rep(i, n) a[i] = 4;
	rep(x, n/ctv)
		rep(m, lcm) {
			int t = m;
			fer(i, x*ctv, x*ctv+ctv)
				if(t % a[i] == 0) t += 2;
				else t += 1;
			p[x][m] = t - m;
		}

//	int ss = 0;
	cin >> q;
	rep(i, q) {
		char type;
		scanf(" %c", &type);
//		type = (i % 3 ? 'A' : 'C');
		int x, y;
		x = nextInt(), y = nextInt();
		//x = 1, y = n;
		if(type == 'C') x = i, y = i % 5 + 1;
		if(type == 'A') {
			x--, y--;
			int t = 0;
			for( ; x+1 <= y && x % ctv; x++)
				if(t % a[x] == 0) t += 2;
				else t += 1;
			for( ; x+ctv <= y; x += ctv)
				t += p[x/ctv][t % lcm];
			for( ; x+1 <= y; x++)
				if(t % a[x] == 0) t += 2;
				else t += 1;
			//cout << t << endl;
			printf("%d\n", t);
			//ss += t;
		} else {
			x--;
			a[x] = y;
			x /= ctv;
			rep(m, lcm) {
				int t = m;
				fer(i, x*ctv, x*ctv+ctv)
					if(t % a[i] == 0) t += 2;
					else t += 1;
				p[x][m] = t - m;
			}
		}
	}

//	cout << ss << endl;

	return 0;
}

