#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lotto;
void solve(vector<int>& a, int index, int select)
{
	if(select == 6)
	{
		for (int num : lotto)
		{
			cout << num;
		}
		cout << endl;
	}
	
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);
	solve(a, index + 1, select + 1);
	lotto.pop_back();
	solve(a, index + 1, select);
}

int lotto_m()
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		solve(s, 0, 0);
		cout << endl;
	}

	return 0;
}