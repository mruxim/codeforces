#include <iostream>

using namespace std;

const int MAXn = 1000 + 10;

int n, m, a, b;
int h[MAXn][MAXn];
int sum[MAXn][MAXn];

int main()
{
	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> h[i][j];
	for (int i = 0; i < n; i++)
	{ int _; cin >> _; }
}
