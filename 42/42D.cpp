#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int a[30][30];
bool used[100000];

int main()
{
	cin >> n;
	a[0][1] = a[1][0] = 1; used[1] = true;
	a[0][2] = a[2][0] = 2; used[2] = true;
//	a[0][3] = a[3][0] = 3; used[3] = true;
	a[1][2] = a[2][1] = 4; used[4] = true;
//	a[1][3] = a[3][1] = 5; used[5] = true;
//	a[2][3] = a[3][2] = 6; used[6] = true;
	for (int i = 3; i < n; i++)
	{
		a[i][0] = a[0][i] = 0;
		for (int j = 1; j < i-1; j++)
			a[i][j] = a[j][i] = a[i][0] + a[j][(j+1)%i] - a[0][(j+1)%i];
		a[i][i-1] = a[i-1][i] = a[i][0] + a[i-1][i-2] - a[0][i-2];
		while (1)
		{
			int j;
			for (j = 0; j < i; j++)
				a[i][j]++, a[j][i]++;
			for (j = 0; j < i; j++)
				if (used[a[i][j]])
					break;
			if (j == i)
				break;
		}
		for (int j = 0; j < i; j++)
			used[a[i][j]] = true;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	{ int _; cin >> _; }
}
