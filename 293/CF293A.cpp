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

const int maxn = 2000000 + 100;

int n;
char a[maxn], b[maxn];
int xy, x, y;
int diff;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	n*= 2;
	cin >> a;
	cin >> b;
	rep (i, n) 
		if (a[i] == '1' && b[i] == '1') xy++;
		else if (a[i] == '1') x++;
		else if (b[i] == '1') y++;
	if (xy % 2)
	{
		diff++;
		if (x) x--;
		else if (y) diff--, y--;
	}
	if (x >= y)
		diff += (x - y + 1) / 2;
	else
		diff -= (y - x) / 2;
	cout << (diff ? (diff > 0 ? "First" : "Second") : "Draw") << endl;

	{ int _; cin >> _; return 0; }
}
