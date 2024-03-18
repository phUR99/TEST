#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	priority_queue<int> max_heap;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (!max_heap.empty() && n == 0)
		{
			cout << max_heap.top() << '\n';
			max_heap.pop();
		}
		else if (max_heap.empty() && n == 0)
		{

			cout << 0 << '\n';
		}
		else
		{
			max_heap.push(n);
		}
	}
}