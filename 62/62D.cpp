#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAXn = 100 + 5;
const int MAXm = 2000 + 5;

int n, m;
int path[MAXm];
vector <int> adj[MAXn];
int ans[MAXm];
bool mark[MAXn][MAXn];

bool dfs (int k, bool s)
{
	if (k == m+1)
		return (s == false);
	int u = ans[k-1];
	for (int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (s && v < path[k]) continue;
		if (mark[u][v]) continue;
		mark[u][v] = mark[v][u] = true;
		ans[k] = v;
		if (dfs (k+1, s && (v == path[k])))
			return true;
		mark[u][v] = mark[v][u] = false;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m+1; i++)
	{
		cin >> path[i];
		path[i]--;
		if (i > 0)
			adj[path[i]].push_back (path[i-1]),
			adj[path[i-1]].push_back (path[i]);
	}
	for (int i = 0; i < n; i++)
		sort (adj[i].begin(), adj[i].end());
	ans[0] = path[0];
	if (dfs (1, true))
	{
		for (int i = 0; i < m+1; i++)
			cout << ans[i] + 1 << ' ';
		cout << endl;
	}
	else
		cout << "No solution" << endl;
	{ int _; cin >> _; }
}
