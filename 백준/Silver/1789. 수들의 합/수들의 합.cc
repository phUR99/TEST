#include <iostream>

using namespace std;

int main() {
	long long int N;
	cin >> N;
	int i=1, cnt = 0;
	while (true)
	{
		if (N < i)
		{
			cout << cnt;
			break;
		}		
		N -= i;
		i++;
		cnt++;
	}
}