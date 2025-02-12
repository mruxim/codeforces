#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define cmx(x,y) x = max (x, y)

const int MAXn = 100 + 5;
const int MAXk = 10 + 2;

int n, m, k;
char s[MAXn][MAXn];
int dp[MAXn][MAXn][MAXk];

int main()
{
	cin >> n >> m >> k;
	k++;
	for (int i = 0; i < n; i++)
		cin >> s[i] + 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] -= '0';

	memset (dp, -1, sizeof dp);
	for (int j = 1; j <= m; j++)
		dp[0][j][s[0][j] % k] = s[0][j];
	for (int i = 0; i < n-1; i++)
		for (int j = 1; j <= m; j++)
			for (int p = 0; p < k; p++)
				if (dp[i][j][p] != -1)
					cmx (dp[i+1][j-1][(p+s[i+1][j-1])%k], dp[i][j][p] + s[i+1][j-1]),
					cmx (dp[i+1][j+1][(p+s[i+1][j+1])%k], dp[i][j][p] + s[i+1][j+1]);

	int res = -1, pos = 0;
	for (int j = 1; j <= m; j++)
		if (dp[n-1][j][0] > res)
			res = dp[n-1][j][0], pos = j;
	cout << res << endl;
	if (res > -1)
	{
		cout << pos << endl;
		string str;
		for (int i = n-1; i > 0; i--)
		{
			res -= s[i][pos];
			if (pos > 1 && dp[i-1][pos-1][res%k] == res)
				pos--, str += "L";
			else
				pos++, str += "R";
		}
		cout << str << endl;
	}
	{ int _; cin >> _; }
}
