#include <iostream>
#include <algorithm>

using namespace std;

const int MAXn = 100000 + 100;

int n;
int ranklist[3*MAXn];
int roster[MAXn][3];
int k;

int rank[3*MAXn];
int team[3*MAXn];

int arr1[3*MAXn], arr2[3*MAXn], result[3*MAXn];

bool cmp (const int &x, const int &y) { return rank[x] < rank[y]; }

int main()
{
	cin >> n;
	for (int i = 0; i < 3*n; i++) cin >> ranklist[i];
	for (int i = 0; i < n; i++) cin >> roster[i][0] >> roster[i][1] >> roster[i][2];
	cin >> k;

	for (int i = 0; i < 3*n; i++) ranklist[i]--;
	for (int i = 0; i < n; i++) roster[i][0]--, roster[i][1]--, roster[i][2]--;
	k--;

	for (int i = 0; i < 3*n; i++) rank[ranklist[i]] = i;
	for (int i = 0; i < n; i++) team[roster[i][0]] = i, team[roster[i][1]] = i, team[roster[i][2]] = i;

	for (int i = 0; i < n; i++) sort (roster[i], roster[i] + 3, cmp);

//	for (int i = 0; i < 3*n; i++) cerr << rank[i] << endl;
//	for (int i = 0; i < n; i++) cerr << roster[i][0] << roster[i][1] << roster[i][2] << endl;

	if (roster[team[k]][0] != k)
	{
		for (int i = 0; i < 3*n-1; i++)
			cout << (i < k ? i : i + 1) + 1 << ' ';
		cout << endl;
	}
	else
	{
		for (int i = 0; i < team[k]; i++)
			for (int j = 0; j < 3; j++)
				arr1[i * 3 + j] = roster[i][j];
		arr2[0] = roster[team[k]][1];
		arr2[1] = roster[team[k]][2];
		if (arr2[0] > arr2[1])
			swap (arr2[0], arr2[1]);
		for (int i = team[k] + 1; i < n; i++)
			for (int j = 0; j < 3; j++)
				arr2[(i - team[k]) * 3 - 1 + j] = roster[i][j];

		sort (arr1, arr1 + team[k] * 3);
		sort (arr2 + 2, arr2 + (n - team[k]) * 3 - 1);
		merge (arr1, arr1 + team[k] * 3, arr2, arr2 + (n - team[k]) * 3 - 1, result);

		for (int i = 0; i < 3*n-1; i++)
			cout << result[i] + 1 << ' ';
		cout << endl;
	}

	{ int _; cin >> _; }
}
