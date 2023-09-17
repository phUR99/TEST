#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

#define ll long long 
using namespace std;

void hanoi(int n, int A, int C, int B) {
	if (n == 1) {
		cout << A << " " << C << '\n';
	}
	else {
		hanoi(n - 1, A, B, C);
		cout << A << " " << C << '\n';
		hanoi(n - 1, B, C, A);
	}


}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 3, 2);
}
