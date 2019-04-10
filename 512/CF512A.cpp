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

const int maxn = 100 + 10;

int n;
string s[maxn];
int g[33][33];
int q[33];
int indeg[33];
int h, t;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];
	rep(i, n-1) {
		string a = s[i], b = s[i+1];
		int p = 0;
		while(p < min(sz(a), sz(b)) && a[p] == b[p]) p++;
		if(sz(a) > sz(b) && p == sz(b)) { cout << "Impossible" << endl; return 0; }
		if(p == sz(a)) continue;
		if(g[a[p] - 'a'][b[p] - 'a']) continue;
		g[a[p] - 'a'][b[p] - 'a'] = 1;
		indeg[b[p] - 'a']++;
	}

	rep(i, 26) if(indeg[i] == 0) q[t++] = i;

	while(h < t) {
		int u = q[h++];
		rep(i, 26) if(g[u][i])
			if(--indeg[i] == 0)
				q[t++] = i;
	}

	if(t < 26) {
		cout << "Impossible" << endl; return 0;
	}

	rep(i, 26) cout << char(q[i] + 'a');
	cout << endl;


	return 0;
}

