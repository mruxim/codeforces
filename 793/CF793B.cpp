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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int maxn = 1000 + 100;

int n, m;
string grid[maxn];
pii S, T;

bool inside(pii p) {
	return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < m;
}

bool no_turn(pii p, pii q) {
	if(p.X == q.X) {
		for(int i = min(p.Y, q.Y); i <= max(p.Y, q.Y); i++)
			if(grid[p.X][i] == '*') return false;
		return true;
	}
	if(p.Y == q.Y) {
		for(int i = min(p.X, q.X); i <= max(p.X, q.X); i++)
			if(grid[i][p.Y] == '*') return false;
		return true;
	}
	return false;
}

bool one_turn(pii p, pii q) {
	if(no_turn(p, pii(p.X, q.Y)) && no_turn(pii(p.X, q.Y), q)) return true;
	if(no_turn(p, pii(q.X, p.Y)) && no_turn(pii(q.X, p.Y), q)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> grid[i];

	rep(i, n) rep(j, n)
		if(grid[i][j] == 'S') S = {i, j};
		else if(grid[i][j] == 'T') T = {i, j};

	if(no_turn(S, T) || one_turn(S, T)) {
		cout << "YES" << endl;
		return 0;
	}

	rep(d, 4) {
		pii p = S;
		while(inside(p)) {
			if(grid[p.X][p.Y] == '*') break;
			if(one_turn(p, T)) {
				cout << "YES" << endl;
				return 0;
			}
			p.X += dx[d], p.Y += dy[d];
		}
	}

	cout << "NO" << endl;

	return 0;
}

