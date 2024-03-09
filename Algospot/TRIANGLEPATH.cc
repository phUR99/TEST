#include <bits/stdc++.h>
using namespace std;
/*


*/
int t;
int arr[100][100];
int cache[100][100];
int n;
//현재 x, y에서 시작해서 맨 아래줄로 내려가는 부분적인 경로의 최대합을 반환한다. (메모이제이션 활용)
int findPath(int x, int y) {
  //맨 아래줄로 도달했을 경우 그 값을 반환한다.
	if (x == n - 1) return arr[x][y];
  //메모이제이션 활용
	int& ret = cache[x][y];
	if (ret != -1) return ret;
  // 밑으로 내려가는 두 길 중 최대합을 활용한다.
	return ret = arr[x][y] + max(findPath(x + 1, y), findPath(x + 1, y + 1));
}


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////

	cin >> t;

	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++) {
				cin >> arr[i][j];
			}
		}
		memset(cache, -1, sizeof(cache));
		int ans = findPath(0, 0);
		cout << ans << '\n';
	}


	/////////////////////////////////////////////////////////////////
	return 0;
}
