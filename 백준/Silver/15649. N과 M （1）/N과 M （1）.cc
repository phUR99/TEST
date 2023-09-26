#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
int arr[10];
bool isused[10];
int n, m;


void func(int k) {
	///////////////////////출력파트//////////////////////
	//k가 계속 증가하다 m이 되면 재귀를 끝내고 다시 이전으로 복귀//
	if(k==m){
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//isused를 체크해서 사용하지 않았다면, k 번째의 숫자를 i로 설정하고 k 번째를 중복해서 쓰지 않기 위해서 isused[i]를 true로 만들어줌(i를 사용)
	//이후 k+1번째를 정하기 위해서 k+1를 넣어줌
	//i를 n까지 순회하면서 사용하지 않은 값을 k+1번째로 정하고 k+2로 넘어감.
	//k=m이 되었다면 다시 돌아가기 위해서 사용한 m번째의 값을 사용하지 않음으로 바꾸고 돌아옴.
	for (int i = 1; i <= n; i++) { 
		if (!isused[i]) { 
			arr[k] = i;
			isused[i] = 1; 
			func(k + 1); 
			isused[i] = 0; 
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}
