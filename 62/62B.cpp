#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define abs(x) ((x)<0?-(x):(x))

const int MAXk = 100000 + 100;

int n, k;
char c[MAXk], s[2*MAXk];
vector <int> p[26];

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> k;
	cin >> c;
	for (int i = 0; i < k; i++)
		p[(int)(c[i] - 'a')].push_back (i);
	while (n--)
	{
		cin >> s;
		long long f = 0;
		int len = strlen (s);
		for (int i = 0; s[i]; i++)
		{
			int ch = (int)(s[i] - 'a');
			if (p[ch].empty())
			{
				f += len;
				continue;
			}
			int v = lower_bound (p[ch].begin(), p[ch].end(), i) - p[ch].begin();
			int tmp = 1 << 25;
			if (v < (int)p[ch].size())
				tmp = abs(p[ch][v] - i);
			if (v > 0)
				tmp = min (tmp, abs (p[ch][v-1] - i));
			f += tmp;
		}
		cout << f << endl;
	}
	{ int _; cin >> _; }
}
