#include <iostream>
#include <string>

using namespace std;

int n, m;
int a, b;
int s[55][55];
int mn = 9999999;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[i][j];
	cin >> a >> b;
	for (int i = 0; i <= n-a; i++)
		for (int j = 0; j <= m-b; j++)
		{
			int t = 0;
			for (int x = i; x < i+a; x++)
				for (int y = j; y < j+b; y++)
					t += s[x][y];
			mn = min (mn, t);
		}
	for (int i = 0; i <= n-b; i++)
		for (int j = 0; j <= m-a; j++)
		{
			int t = 0;
			for (int x = i; x < i+b; x++)
				for (int y = j; y < j+a; y++)
					t += s[x][y];
			mn = min (mn, t);
		}
	cout << mn << endl;
	{ int _; cin >> _; }
}
