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
	long long f=1,l=M;
	long long tmp, med;
	long long answer = 0;
	while (f <= l)
	{	
		tmp = 0;
		med = (f + l) / 2;
		for (auto i : h) {
			tmp += i / med;
		}
		if (tmp < m) {		
			l= med - 1;		
		}
		else 
		{
			f = med + 1;
			if (med >= answer) answer = med;
			
 		}
		
	}
	cout << answer;
}