// .... .... .... !

#include <iostream>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

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

const int maxn = 100 + 10;

int n;
int x[maxn], y[maxn];
bool mark[maxn];

void dfs (int v)
{
	if (mark[v]) return;
	mark[v] = 1;
	rep (i, n) if (x[v] == x[i] || y[v] == y[i])
		dfs (i);
}

int main()
{
	cin >> n;
	rep (i, n) cin >> x[i] >> y[i];

	int cnt = 0;
	rep (i, n) if (!mark[i])
	{
		cnt++;
		dfs (i);
	}
	cout << cnt - 1 << endl;
	{ int _; cin >> _; }
	return 0;
}
