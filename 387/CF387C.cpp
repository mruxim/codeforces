
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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
#include <bitset>

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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

string s;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s;
	int n = sz(s);
	int ans = 0;
	rep (i, n) if (s[i] != '0')
	{
		int j = i+1;
		while (j < n && s[j] == '0') j++;
		if (j == n) ans++;
		else
		{
			int k = j+1;
			while (k < n && s[k] == '0') k++;
			if (k-j < j || (k-j==j && !lexicographical_compare (s.begin(), s.begin()+j, s.begin()+j, s.begin()+k)))
				ans++;
			else
				ans = 0;
		}
		i = j-1;
	}

	cout << ans << endl;

	{ return 0; }
}

