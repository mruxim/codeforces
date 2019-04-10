// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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

const int maxn = 150000 + 100;

int n;
vector<int> v[maxn];
int par[maxn];

int find(int x) {
	if(par[x] == -1) return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(sz(v[x]) < sz(v[y]))
		swap(x, y);
	par[y] = x;
	for(int t: v[y]) v[x].pb(t);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	rep(i, n) v[i].pb(i), par[i] = -1;

	rep(i, n-1) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		merge(x, y);
	}

	int r = find(0);
	rep(i, sz(v[r])) cout << (i ? " " : "") << v[r][i] + 1;
	cout << endl;

	return 0;
}

