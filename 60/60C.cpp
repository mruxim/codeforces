#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define pb push_back

const int MAXp = 1000000 + 1000;
const int MAXn = 100 + 10;

int n, m;
vector <int> adj[MAXn];
vector <int> gcd[MAXn], lcm[MAXn];
int ip[MAXp];

int val[MAXn], f[MAXn];

int get (int x, int y)
{
	int r = x;
	while (r % y == 0)
		r /= y;
	return x / r;
}

bool dfs (int u, int x, int p)
{
	if (f[u] != 0 && f[u] != x)
	{
		f[u] = 0;
		return false;
	}
	if (f[u] == x)
		return true;
	f[u] = x;
	for (int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (x == get (gcd[u][i], p))
		{
			if (!dfs (v, get (lcm[u][i], p), p))
			{
				f[u] = 0;
				return false;
			}
		}
		else if (x == get (lcm[u][i], p))
		{
			if (!dfs (v, get (gcd[u][i], p), p))
			{
				f[u] = 0;
				return false;
			}
		}
		else 
		{
			f[u] = 0;
			return false;
		}
	}
	return true;
}

int main()
{
	ip[0] = ip[1] = true;
	for (int i = 2; i*i < MAXp; i++)
		if (!ip[i])
			for (int j = i*i; j < MAXp; j += i)
				ip[j] = true;

	cin >> n >> m;
	bool Yes = true;
	while (m--)
	{
		int u, v, g, l;
		cin >> u >> v >> g >> l;
		if (l % g != 0)
			Yes = false;
		u--, v--;
		adj[u].pb (v);
		adj[v].pb (u);
		gcd[u].pb (g), lcm[u].pb (l);
		gcd[v].pb (g), lcm[v].pb (l);
	}

	fill (val, val + n, 1);
	for (int p = 0; p < MAXp && Yes; p++)
		if (!ip[p])
		{
			fill (f, f + n, 0);
			for (int i = 0; i < n && Yes; i++)
				if (f[i] == 0)
				{
					if ((int)adj[i].size() == 0)
					{
						f[i] = 1;
						continue;
					}
					if (!dfs (i, get (gcd[i][0], p), p))
						if (!dfs (i, get (lcm[i][0], p), p))
							Yes = false;
				}
			for (int i = 0; i < n; i++)
				val[i] *= f[i];
//			cerr << p << " : ";
//			for (int i = 0; i < n; i++) cerr << f[i] << ' '; cerr << endl;
		}
	if (Yes)
	{
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			cout << val[i] << ' ';
		cout << endl;
	}
	else
		cout << "NO" << endl;
	{ int _; cin >> _; }
}
