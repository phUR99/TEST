#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char room[101][101];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s = "";
	int cnt_row=0, cnt_col = 0;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			room[i][j] = temp[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				if (room[i][j]=='.') s += '.';
				if (s.size() >= 2) cnt_row++;
				s.clear();
			}
			else {
				if (room[i][j] == 'X')  {
					if (s.size() >= 2) cnt_row++;
					s.clear();
				}
				else if (room[i][j] == '.') s += '.';
				
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				if (room[j][i] == '.') s += '.';
				if (s.size() >= 2) cnt_col++;
				s.clear();
			}
			else {
				if (room[j][i] == 'X') {
					if (s.size() >= 2) cnt_col++;
					s.clear();
				}
				else if (room[j][i] == '.') s += '.';

			}
		}

	}
	cout << cnt_row << " " << cnt_col;
}
