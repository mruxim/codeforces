// .... .... .....!
// P..... C.....!

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
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5*10000 + 100;
const int maxl = 100 + 10;

int n;
char s[5*10000 + 1000];
vector<int> ch[26];
int dp[maxn][maxl];

int main()
{
//	ios::sync_with_stdio (false);

	memset (dp, 50, sizeof dp);

	gets (s);
	n = strlen (s);
	rep (i, n) ch[s[i]-'a'].pb (i);
	rep (i, 26) ch[i].pb (n+100);

	rof (j, n, 0) dp[j][0] = j-1, dp[j][1] = j;

	fer (i, 2, maxl)
	{
		int lm = n+50;
		rof (j, n, 0)
		{
			int pos = upper_bound (all (ch[s[j]-'a']), lm) - ch[s[j]-'a'].begin();
			dp[j][i] = ch[s[j]-'a'][pos];
			lm = min (lm, dp[j][i-2]);
		}
	}
	int ans = 100;
	int st = 0;
	while (1)
	{
		bool found = false;
		rep (i, n) if (dp[i][ans] < n) { st = i; found = true; break; }
		if (found) break;
		ans--;
	}

	vector<char> vc;
	int end = n;
	while (ans >= 1)
	{
		while (dp[st][ans] >= end) st++;
		putchar (s[st]);
		if (ans >= 2) vc.pb (s[dp[st][ans]]);
		end = dp[st][ans];
		st++;
		ans -= 2;
	}
	while (sz(vc))
		putchar (vc.back()), vc.pop_back();

	{ int _; cin >> _; return 0; }
}
