#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculate(vector<int> a)
{
	int sum = 0;
	for (int i = 0; i < a.size() - 1; i++)
	{
		sum += abs(a[i] - a[i + 1]);
	}
	return sum;
}

int max_diff()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	do {
		int temp = calculate(a);
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans;

	return 0;
}