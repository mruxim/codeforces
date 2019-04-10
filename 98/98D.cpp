// .... .... .... !

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
int d[22];
vector <pii> moves;

void move (int fr, int to, int cur, bool rev)
{
	if (cur == n) return;

	int as = 6 - fr - to;
	int next = cur;
	while (next < n && d[next] == d[cur]) next++;
	if (next - cur == 1 || rev)
	{
		move (fr, as, next, true);
		rep (i, next - cur) moves.push_back ({fr, to});
		move (as, to, next, true);
	}
	else
	{
		move (fr, to, next, true);
		rep (i, next - cur - (next == n)) moves.push_back ({fr, as});
		if (next == n)	moves.push_back ({fr, to});
		else		move (to, fr, next, true);
		rep (i, next - cur - (next == n)) moves.push_back ({as, to});
		move (fr, to, next, false);
	}
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> d[i];

	move (1, 3, 0, false);

	cout << sz(moves) << endl;
	for (auto &m : moves)
		cout << m.first << ' ' << m.second << endl;
	{ int _; cin >> _; }
	return 0;
}
