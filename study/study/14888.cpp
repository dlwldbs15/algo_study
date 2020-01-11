#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> calc(vector<int>& s, int index, int cur, int plus, int minus, int mul, int div)
{
	int n = s.size();
	if (index == n) {
		return make_pair(cur, cur);
	}

	vector<pair<int, int>> res;
	if (plus > 0)
	{
		res.push_back(calc(s, index + 1, cur + s[index], plus - 1, minus, mul, div));
	}
	if (minus > 0)
	{
		res.push_back(calc(s, index + 1, cur - s[index], plus, minus - 1, mul, div));
	}
	if (mul > 0)
	{
		res.push_back(calc(s, index + 1, cur * s[index], plus, minus, mul - 1, div));
	}
	if (div > 0)
	{
		res.push_back(calc(s, index + 1, cur / s[index], plus, minus, mul, div - 1));
	}

	auto ans = res[0];
	for (auto p : res)
	{
		if (ans.first < p.first)
			ans.first = p.first;
		if (ans.second > p.second)
			ans.second = p.second;
	}
	return ans;
}

int math()
{
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	auto p = calc(s, 0, s[0], plus, minus, mul, div);
	cout << p.first << endl;
	cout << p.second << endl;

	return 0;
}