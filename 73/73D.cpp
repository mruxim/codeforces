#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXn = 1000 * 1000 + 100;

int n, k, m;
vector <int> v[MAXn];
bool mark[MAXn];
int a[MAXn], p;

int dfs (int x)
{
	if (mark[x]) return 0;
	mark[x] = 1;
	int ret = 1;
	for (int i = 0; i < (int)v[x].size(); i++)
		ret += dfs (v[x][i]);
	return ret;
}

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back (b);
		v[b].push_back (a);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			a[p++] = dfs (i);
	sort (a, a + p);

	if (k == 1)
	{
		cout << max (p-2, 0) << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < p; i++)
		sum += min (a[i], k);
	cout << max (0, p - sum/2 - 1) << endl;
	{ int _; cin >> _; }
}
