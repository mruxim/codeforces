// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

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
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 * 1000 + 100;

int n, r, c;
string s[maxn];
int len[maxn];
int dp[maxn][22];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> r >> c; c++;
	rep (i, n) { cin >> s[i]; len[i] = sz(s[i]) + 1; }

	int tot = 0, end = n;

	rep (j, 22) dp[n][j] = n;

	rof (i, n, 0)
	{
		tot += len[i];
		while (tot > c) tot -= len[--end];

		dp[i][0] = end;
		fer (j, 1, 22) dp[i][j] = dp[dp[i][j-1]][j-1];
	}

	int mx = -1, start = 0;

	rep (i, n)
	{
		int rr = r;
		int end = i;
		rep (j, 22)
		{
			if (rr & 1) end = dp[end][j];
			rr /= 2;
		}

		if (end - i > mx) mx = end - i, start = i;
	}

	int now = c+1, dt = 0;
	fer (i, start, start + mx)
	{
		if (now+len[i] > c) { now = 0; if (dt) cout << endl; }
		else cout << " ";
		now += len[i];
		dt = 1;
		cout << s[i];
	}
	cout << endl;

	{ int _; cin >> _; return 0; }
}
