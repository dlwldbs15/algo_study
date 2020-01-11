#include <iostream>
#include <vector>

using namespace std;

int go(int sum, int goal)
{
	if (sum > goal)
		return 0;
	else if (sum == goal)
		return 1;

	int now = 0;
	for (int i = 1; i <= 3; i++)
		now += go(sum + i, goal);
	return now;
}

int sumNumber()
{
	int n;
	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; i++)
	{
		cin >> k[i];
	}

	for (int i = 0; i < k.size(); i++)
	{
		cout << go(0, k[i]) << endl;
	}
	return 0;
}