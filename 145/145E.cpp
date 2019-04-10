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
const int maxm = 300 * 1000 + 100;

int n, m;
string s;

int inc[4*maxn], des[4*maxn], cnt4[4*maxn], cnt7[4*maxn];
int flag[4*maxn];

void update (int x)
{
	cnt4[x] = cnt4[2*x+1] + cnt4[2*x+2];
	cnt7[x] = cnt7[2*x+1] + cnt7[2*x+2];
	inc[x] = max (cnt4[2*x+1] + inc[2*x+2], inc[2*x+1] + cnt7[2*x+2]);
	des[x] = max (cnt7[2*x+1] + des[2*x+2], des[2*x+1] + cnt4[2*x+2]);
}

void shift (int x)
{
	if (flag[x] == false) return;
	flag[x] = false;
	swap (inc[2*x+1], des[2*x+1]); swap (cnt4[2*x+1], cnt7[2*x+1]);
	swap (inc[2*x+2], des[2*x+2]); swap (cnt4[2*x+2], cnt7[2*x+2]);
	flag[2*x+1] ^= true;
	flag[2*x+2] ^= true;
}

void make (int x, int l, int r)
{
	if (r - l == 1) { cnt4[x] = (s[l] == '4'); cnt7[x] = (s[l] == '7'); inc[x] = des[x] = 1; return; }

	int md = (l + r) / 2;
	make (2*x+1, l, md);
	make (2*x+2, md, r);

	update (x);
}

void change (int x, int l, int r, int L, int R)
{
	if (R <= l || r <= L) return;
	if (L <= l && r <= R) { swap (inc[x], des[x]); swap (cnt4[x], cnt7[x]); flag[x] ^= true; return; }

	shift (x);

	int md = (l + r) / 2;

	change (2*x+1, l, md, L, R);
	change (2*x+2, md, r, L, R);

	update (x);
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	cin >> s;

	make (0, 0, n);

	while (m-- > 0)
	{
		string com;
		cin >> com;
		if (com == "count")
			cout << inc[0] << endl;
		else
		{
			int l, r;
			cin >> l >> r; l--;
			change (0, 0, n, l, r);
		}
	}

	{ int _; cin >> _; return 0; }
}
