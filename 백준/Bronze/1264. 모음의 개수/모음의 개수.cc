#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
char arr[5] = { 'a', 'e', 'i', 'o', 'u' };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int ans = 0;
		string temp;
		getline(cin, temp);
		if (temp == "#") break;
		for (auto i : temp)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tolower(i) == arr[j]) ans++;
			}
			
		}
		cout << ans << '\n';
		
	}

}
