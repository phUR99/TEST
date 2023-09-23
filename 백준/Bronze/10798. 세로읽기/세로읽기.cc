#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
string arr[5];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 15; i++)

		for (int j = 0; j < 5; j++)

			if (i < arr[j].size()) 

				cout << arr[j][i];

	cout << '\n';



	return 0;
}
