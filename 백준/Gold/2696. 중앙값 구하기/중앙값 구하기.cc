#include <bits/stdc++.h>
using namespace std;
/*
#2696 : 2개의 힙을 사용해서 푸는 문제
출력 부분이 살짝 귀찮다.

*/
int t, m;


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	
	cin >> t;
	while (t--)
	{
		priority_queue<int> first_Heap;
		priority_queue<int, vector<int>, greater<int>> second_Heap;
		vector<int> ans;


		cin >> m;
		cout << (m + 1) / 2 << '\n';
		for (int i = 1; i <= m; i++)
		{
			int cur;
			cin >> cur;
			if (first_Heap.size() <= second_Heap.size())
			{
				first_Heap.push(cur);
			}
			else
			{
				second_Heap.push(cur);
			}
			while (!second_Heap.empty() && second_Heap.top() < first_Heap.top())
			{
				first_Heap.push(second_Heap.top());
				second_Heap.pop();
				second_Heap.push(first_Heap.top());
				first_Heap.pop();
			}
			if (i % 2 == 1) ans.push_back(first_Heap.top());
		}
		for (int i = 0; i < ans.size(); i++)
		{
			if (i != 0 && i % 10 == 0) cout << '\n';
			cout << ans[i] << ' ';
			
		}

		cout << '\n';
		
	}


	
	
	/////////////////////////////////////////////////////////////////
	return 0;
}