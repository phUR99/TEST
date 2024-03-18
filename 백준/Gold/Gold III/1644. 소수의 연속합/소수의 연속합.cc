#include <bits/stdc++.h>
using namespace std;

/*


*/

bool isP[4'000'005];
int n;

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	vector<int> prime;

	cin >> n;
	for (int i = 2; i*i <= n; i++)
	{
		if (isP[i] == true) continue;
		for (int j = i*i; j <= n; j +=i)
		{
			isP[j] = true;
		}
	}

	int p = 0;
	for (int i = 2; i <= n; i++)
	{
		if (isP[i] == false) { 
			prime.push_back(i); 
			p++;
		}

	}

	int st = 0;
	int ed = 0;
	int cnt = 0;
	int cur = prime[0];
	
	while (st < p && st <= ed)
	{

		
		while (ed < p && cur < n) {
			ed++;
			cur += prime[ed];
		}
		if (cur == n) cnt++;
		cur -= prime[st];
		st++;
	}
	
	cout << cnt;

	return 0;
}