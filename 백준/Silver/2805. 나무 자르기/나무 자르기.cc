#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m, temp;
	cin >> n >> m;
	vector<int> h;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		h.push_back(temp);
	}
	int M = *max_element(h.begin(), h.end());
	long long f=0, med=(M+0)/2, l=M;
	long long tmp;
	long long answer = 0;
	while (f <= l)
	{	
		tmp = 0;
		for (auto i : h) {
			if(i > med) tmp += i - med;
		}
		if (tmp < m) {		
			l= med - 1;
			med = (f + l) / 2;
		}
		else 
		{
			if (med >= answer) answer = med;
			f = med + 1;
			med = (f + l) / 2;		
 		}
		
	}
	cout << answer;
}