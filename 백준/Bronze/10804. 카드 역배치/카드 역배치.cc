#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	int arr[21];
	stack<int> stk;
	for (int i = 0; i < 21; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		for (int j = a; j <= b; j++)
		{
			stk.push(arr[j]);
		}
		for (int j = a; j <= b; j++)
		{
			arr[j] = stk.top();
			stk.pop();
		}

	}
	for (int i =1; i < 21; i++ )
	{
		cout << arr[i] << " ";
	}
}