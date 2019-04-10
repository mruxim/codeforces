
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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 20+5;

char s[maxn];
int len;

void gen (int n, bool rev = false) {
	if (n == 0) s[len] = 0, puts (s);
	if (n <= 0) return;

	if (rev) s[len++] = 'w', gen (n-2, !rev), len--;
	s[len++] = 'i', gen (n-1, !rev), len--;
	if (!rev) s[len++] = 'w', gen (n-2, !rev), len--;
}


int main() {
	int n;
	scanf ("%d", &n);
	gen (n);

	{ return 0; }
}

