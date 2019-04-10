#include <iostream>
#include <vector>
#include <map>

using namespace std;

char op[3];

long long solve (vector <long long> v)
{
	int n = (int)v.size();
	long long ret = 1LL << 62;
	if (n == 1)
		return v[0];
	if (op[4 - n] == '+')
	{
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				vector <long long> dv;
				for (int k = 0; k < n; k++)
					if (k != i && k != j)
						dv.push_back (v[k]);
				dv.push_back (v[i] + v[j]);
				ret = min (ret, solve (dv));
			}
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				vector <long long> dv;
				for (int k = 0; k < n; k++)
					if (k != i && k != j)
						dv.push_back (v[k]);
				dv.push_back (v[i] * v[j]);
				ret = min (ret, solve (dv));
			}
	}
	return ret;
}

int main()
{
	vector <long long> v(4);
	for (int i = 0; i < 4; i++) cin >> v[i];
	for (int i = 0; i < 3; i++) cin >> op[i];
	cout << solve (v) << endl;
	{ int _; cin >> _; }
}
