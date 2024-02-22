#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
5626 : 항상 양 끝은 0일 수밖에 없다.
N : 10000 완전탐색 절대 불가능
가능한 h <= n/2
1. d[i][j] : i번째 위치에서 j의 높이일 때의 경우의 수
2. 점화식? : d[i][j] = d[i-1][j] + d[i-1][j-1] +d[i-1][j+1] :
ex) 높이가 결정되는 경우 j <= k인 경우만 구하면 된다.
3. 초깃값? : d[1][0] = 0 , a[1][0] 이 0이나 -1이 아닐 경우에는 가능한 경우의 수가 없을 것이다.

메모리 초과 : long long을 10^8 개 선언 -> 800MB 예상
따라서 슬라이딩 윈도우 기법을 사용해서 메모리 사용을 최적화한다.

*/
const int di = 1'000'000'007;

long long d[2][5050];
int a[10050];
int n;

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (a[1] == -1 || a[1] == 0) d[1][0] = 1;

	for (int i = 2; i <= n; i++)
	{
		int idx = (i) % 2;
		int b_idx = (i - 1) % 2;

		if (a[i] == -1) {
			d[idx][0] = (d[b_idx][0] + d[b_idx][1]) %di;
			for (int j = 1; j <= n / 2; j++)
			{
				d[idx][j] = (d[b_idx][j - 1] + d[b_idx][j] + d[b_idx][j + 1]) %di;
			}		
		}
		else if (a[i] == 0) {
			d[idx][0] = (d[b_idx][0] + d[b_idx][1]) %di;
		}
		else
		{
			d[idx][a[i]] = (d[b_idx][a[i] - 1] + d[b_idx][a[i]] + d[b_idx][a[i] + 1]) %di;
		}
		fill(d[b_idx], d[b_idx] + n/2 + 1, 0);

	}
	int ans = d[n%2][0];
	cout << ans;

	 
	return 0;
}