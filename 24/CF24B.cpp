#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int points[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int t, n;
map <string, int> point;
map <string, vector <int> > pos;
set <string> names;

bool bet1 (string &s, string &t)
{
	if (point[s] != point[t]) return point[s] > point[t];
	for (int i = 0; i < 55; i++)
		if (pos[s][i] != pos[t][i])
			return pos[s][i] > pos[t][i];
	return true;
}

bool bet2 (string &s, string &t)
{
	if (pos[s][0] != pos[t][0])
		return pos[s][0] > pos[t][0];
	if (point[s] != point[t]) return point[s] > point[t];
	for (int i = 1; i < 55; i++)
		if (pos[s][i] != pos[t][i])
			return pos[s][i] > pos[t][i];
	return true;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string name;
			cin >> name;
			names.insert (name);
			if (pos.count (name) == 0)
			{
				vector<int> &v = pos[name];
				v.resize(55);
				for (int j = 0; j < 55; j++)
					v[j] = 0;
			}
			if (i < 10)
				point[name] += points[i];
			pos[name][i]++;
		}
	}
	string f1 = *names.begin(), f2 = f1;
	for (set <string>::iterator it = names.begin(); it != names.end(); it++)
	{
		string str = *it;
		if (bet1 (str, f1))
			f1 = str;
		if (bet2 (str, f2))
			f2 = str;
	}
	cout << f1 << endl << f2 << endl;
	{ int _; cin >> _; }
}
