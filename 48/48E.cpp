#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int H, T, R;
int n, m;
int a[500][2], b[500][2];
int f[500][500];
pair <int, int> p[500*500];
int head, tail;
bool draw = false;
int res;
int mark[500][500];
int z[500][500];

bool dfs (int h, int t)
{
	if (mark[h][t] == 1) return true;
	if (mark[h][t] == 2) return false;
	mark[h][t] = 1;
	for (int i = 0; i < min (n, h); i++)
	{
		int h2 = h - (i+1) + a[i][0], t2 = t + a[i][1];
		if (h2 + t2 > R)
		{
			z[h][t] = max (z[h][t], 1);
			continue;
		}
		if (dfs (h2, t2)) return true;
		else
			z[h][t] = max (z[h][t], z[h2][t2] + 1);
	}
	for (int i = 0; i < min (m, t); i++)
	{
		int h2 = h + b[i][0], t2 = t - (i+1) + b[i][1];
		if (h2 + t2 > R)
		{
			z[h][t] = max (z[h][t], 1);
			continue;
		}
		if (dfs (h2, t2)) return true;
		else
			z[h][t] = max (z[h][t], z[h2][t2] + 1);
	}
	mark[h][t] = 2;
	return false;
}

int main()
{
	cin >> H >> T >> R;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i][0] >> b[i][1];

	memset (f, -1, sizeof f);
	f[H][T] = 0;
	p[tail++] = make_pair (H, T);
	while (head < tail)
	{
		pair <int, int> v = p[head++];
		int h = v.first, t = v.second;
		for (int i = 0; i < min (n, h); i++)
		{
			int h2 = h - (i+1) + a[i][0], t2 = t + a[i][1];
			if (h2 + t2 > R)
			{
				res = max (res, f[h][t] + 1);
				continue;
			}
			if (f[h2][t2] == -1)
			{
				f[h2][t2] = f[h][t] + 1;
				p[tail++] = make_pair (h2, t2);
			}
//			else if (f[h2][t2] < f[h][t])
//				draw = true;
		}
 		for (int i = 0; i < min (m, t); i++)
		{
			int h2 = h + b[i][0], t2 = t - (i+1) + b[i][1];
			if (h2 + t2 > R)
			{
				res = max (res, f[h][t] + 1);
				continue;
			}
			if (f[h2][t2] == -1)
			{
				f[h2][t2] = f[h][t] + 1;
				p[tail++] = make_pair (h2, t2);
			}
//			else if (f[h2][t2] < f[h][t])
//				draw = true;
		}
	}
	if (f[0][0] != -1)
		cout << "Ivan" << endl << f[0][0] << endl;
	else if (dfs (H, T))
		cout << "Draw" << endl;
	else
		cout << "Zmey" << endl << z[H][T] << endl;
	{ int _; cin >> _; }
}
