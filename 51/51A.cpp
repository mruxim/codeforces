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
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
char s[10];
bool f[6*6*6*6];

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> s;
		int a = s[0] - '1', b = s[1] - '1';
		cin >> s;
		int c = s[1] - '1', d = s[0] - '1';
		int x = a*6*6*6+b*6*6+c*6+d;
		x = min (x, b*6*6*6+c*6*6+d*6+a);
		x = min (x, c*6*6*6+d*6*6+a*6+b);
		x = min (x, d*6*6*6+a*6*6+b*6+c);
		f[x] = 1;
		if (n) cin >> s;
	}
	int ans = 0;
	rep (i, 6*6*6*6)
		ans += f[i];
	cout << ans << endl;
	{ int _; cin >> _; }
	return 0;
}
