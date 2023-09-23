#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		float n;
		cin >> n;
		vector<float> vec;
		float sum = 0;
		for(int i=0; i<n; i++)
		{
			float temp;
			cin >> temp;
			vec.push_back(temp);
			sum += temp;
		}
		float aver = sum / n;
		float cnt = 0;
		for (auto i : vec)
		{
			if (i > aver) cnt++;
		}
		cout << fixed << setprecision(3) << (cnt / n)*100 << "%\n";
	}
	
}
