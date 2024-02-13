#include <bits/stdc++.h>
using namespace std;



int isused[26];
int n, k;
string str[55];
int ans = 0;

void func(int idx, int t) {
	//1. 체크인
	if (isused[idx] != 2)
	{
		isused[idx] = 1;
		t++;
	}
	//2. 목적지
	if (t == k) {
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{			
			bool flag = true;
			for (int j = 0; j < str[i].length(); j++) 
			{
				if (isused[str[i][j] - 'a'] == 0) flag = false;

			}
			if (flag == true) tmp++;

		}
		ans = max(ans, tmp);
	}
	//3. 순회
	else
	{
		for (int i = idx + 1; i < 26; i++) {
			//4. 갈 수 있는가			
			if (isused[i] == 2) continue;
			//5. 간다					
			func(i, t);
			
		}
	}
	//6. 체크아웃
	if (isused[idx] != 2)
	{
		t--;
		isused[idx] = false;
	}

}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	if (k == 26) {
		cout << n;
		return 0;
	}

	isused['a' - 'a'] = 2;
	isused['n' - 'a'] = 2;
	isused['t' - 'a'] = 2;
	isused['i' - 'a'] = 2;
	isused['c' - 'a'] = 2;

	k = k - 5;
	func(0, 0);

	cout << ans;
	return 0;
}