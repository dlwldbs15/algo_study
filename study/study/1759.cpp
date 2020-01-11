#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//n :만들어야 하는 암호의 길이
//alpha : 사용할 수 있는 알파벳
//password : 현재까지 만든 암호
//i : 사용할지 말지 결정해야하는 알파벳의 인덱스

bool check(string password)
{
	int ja = 0;
	int mo = 0;
	for (auto x : password)
	{
		if (x == 'a' || x == 'i' ||
			x == 'o' ||	x == 'u')
			mo++;
		else
			ja++;
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char>& alpha, string password, int i)
{
	if (password.length() == n) //정답
	{
		if (check(password))
		{
			cout << password << endl;
		}
		return;
	}

	if (i < alpha.size())
	{
		go(n, alpha, password + alpha[i], i + 1);
		go(n, alpha, password, i + 1);
	}
}

int main()
{
	int L, C;
	cin >> L >> C;
	vector<char> alpha(C);
	for (int i = 0; i < C; i++)
		cin >> alpha[i];

	sort(alpha.begin(), alpha.end());
	go(L, alpha, "", 0);
	return 0;
}