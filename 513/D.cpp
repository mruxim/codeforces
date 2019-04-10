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

inline int getint () {
	register char ch;
	register int res;
	while((ch = getchar()) < '0');
	for(res = ch - '0'; (ch = getchar()) >= '0'; res = res * 10 + ch - '0');
	return res;
}

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000000 + 100;

int n, c;
int minL[maxn], maxL[maxn], minR[maxn], maxR[maxn];
vector<int> ans;
bool can = true;

int go(int a, int b) {
	if(a >= b) return a;
	int f = a+1;
	if(maxL[a] != -1) f = go(f, maxL[a] + 1);
	ans.pb(a);
	if(!can) return -1;
	if(minR[a] < f) { can = false; return -1; }
	f = go(f, max(b, maxR[a] + 1));
	return f;
}

int main() {
	n = getint();
	c = getint();

	rep(i, n) minL[i] = minR[i] = n, maxL[i] = maxR[i] = -1;

	rep(i, c) {
		int a = getint(); a--;
		int b = getint(); b--;
		static char s[10];
		gets(s);
		if(b <= a) { cout << "IMPOSSIBLE" << endl; return 0; }
		if(s[0] == 'L') smin(minL[a], b), smax(maxL[a], b);
		else smin(minR[a], b), smax(maxR[a], b);
	}

	go(0, n);

	if(!can) cout << "IMPOSSIBLE" << endl;
	else {
		for(int x: ans) printf("%d ", x+1);
		cout << endl;
	}

	return 0;
}

