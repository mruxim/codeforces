// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

int n;
map <string, int> score;
vi data;

int main()
{
	cin >> n;
	rep (i, n)
	{
		string name;
		int point;
		cin >> name >> point;
		if (score.find (name) == score.end())
			score[name] = point;
		else
			cmx (score[name], point);
	}
	
	fch (it, score)
		data.pb (it->second);

	sort (all (data));

	int tot = sz (data);

	cout << tot << endl;

	fch (it, score)
	{
		int pos = upper_bound (all (data), it->second) - data.begin();
		cout << (it->first) << ' ';
		if ((tot - pos) * 100 > tot * 50) cout << "noob" << endl;
		else if ((tot - pos) * 100 > tot * 20) cout << "random" << endl;
		else if ((tot - pos) * 100 > tot * 10) cout << "average" << endl;
		else if ((tot - pos) * 100 > tot * 1) cout << "hardcore" << endl;
		else cout << "pro" << endl;
	}
	{ int _; cin >> _; }
}
