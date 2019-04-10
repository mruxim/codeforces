#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXk = 100 + 5;

string s;
int k, n;
int w[128][128];
int dp[MAXk][MAXk][128];

int main()
{
	cin >> s >> k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c1, c2;
		int v;
		cin >> c1 >> c2 >> v;
		w[(int)c1][(int)c2] = v;
	}
	for (int i = 0; i < MAXk; i++)
		for (int j = 0; j < MAXk; j++)
			for (int z = 0; z < 128; z++)
				dp[i][j][z] = -9999999;
	dp[0][0]['z'+1] = 0;
	for (int i = 0; i < (int)s.length(); i++)
		for (int j = 0; j <= min (i+1, k); j++)
			for (int p = 'a'; p <= ('z'+1); p++)
				for (int c = 'a'; c <= 'z'; c++)
				{
					if (c == s[i])
						dp[i+1][j][c] = max (dp[i+1][j][c], dp[i][j][p] + w[p][c]);
					else if (j)
						dp[i+1][j][c] = max (dp[i+1][j][c], dp[i][j-1][p] + w[p][c]);
				}
	int r = -999999;
	for (int i = 0; i <= k; i++)
		for (int j = 'a'; j <= 'z'; j++)
			r = max (r, dp[s.length()][i][j]);
	cout << r << endl;
	{ int _; cin >> _; }
}
