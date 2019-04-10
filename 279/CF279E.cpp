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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

char s[1111111];

int main()
{
//	ios::sync_with_stdio (false);

	scanf ("%s", s+1);
	s[0] = '0';
	int n = strlen(s);
	s[n++] = '0';
	int ans = 0;

	rep (i, n-1)
	{
		if (strncmp (s+i, "010", 3) == 0) s[i+1] = '0', ans++;
		if (strncmp (s+i, "101", 3) == 0) s[i+1] = '1', ans++;
		ans += (s[i] != s[i+1]);
	}
	printf ("%d\n", ans);

	{ int _; cin >> _; return 0; }
}
