#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	int cnt;
	for (int j = 0; j < 3; j++)
	{
		cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> tmp;
			if (tmp == 0) cnt++;
		}
		switch (cnt)
		{
		case 0:
			cout << "E" << "\n";
			break;
		case 1:
			cout << "A" << "\n";
			break;
		case 2:
			cout << "B" << "\n";
			break;
		case 3:
			cout << "C" << "\n";
			break;
		case 4:
			cout << "D" << "\n";
			break;
		}
	}
}