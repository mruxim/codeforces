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

string s, sss;
int a[99999];
int k;
int store[99999], len;

int main()
{
	while (cin >> sss && sss != "$$$") s += sss;
	int pos = 0;
	while (pos < sz(s))
	{
		pos++;
		if ((s[pos] == 't' && s[pos+1] == 'r') || ((s[pos] == '/' && s[pos+1] == 't' && s[pos+2] == 'r'))) ;
		else if (s[pos] == 't' && s[pos+1] == 'd') a[k]++;
		else if (s[pos] == '/' && s[pos+1] == 't' && s[pos+2] == 'd') ;
		else if (s[pos] == 't' && s[pos+1] == 'a') k++;
		else if (s[pos] == '/' && s[pos+1] == 't' && s[pos+2] == 'a') store[len++] = a[k], a[k] = 0, k--;
		while (s[pos] != '>') pos++; pos++;
	}
	sort (store, store + len);
	rep (i, len) cout << store[i] << ' ';
	cout << endl;
	{ int _; cin >> _; }
	return 0;
}
