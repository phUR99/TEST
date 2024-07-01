#include <string>
#include <vector>
#include <string.h>
/*
사다리꼴 -> 정삼각형의 예외 모양.. 예외를 바로 계산하기 VS 전체에서 예외를 제외하기..
나올 수 있는 경우의 수 ? 4 ^1e6.. 백트래킹으로는 해결하기 어렵다 -> 메모이제이션 활용하기..


*/
using namespace std;
int cache[100005][4];
int arr[100005];
const int d = 10007;



int solution(int n, vector<int> tops) {
    int answer = 0;
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        arr[i+1] = tops[i];
    }
    cache[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // 0 왼 1 오 2 위 3 X
        if(arr[i]){
            cache[i][0] = (cache[i-1][0]                 + cache[i-1][2] + cache[i-1][3]) % d;
            cache[i][1] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2] + cache[i-1][3]) % d;
            cache[i][2] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2] + cache[i-1][3]) % d;
            cache[i][3] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2] + cache[i-1][3]) % d;
        }        
        else
        {
            cache[i][0] = (cache[i-1][0]                 + cache[i-1][2] + cache[i-1][3]) % d;
            cache[i][1] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2] + cache[i-1][3]) % d;            
            cache[i][3] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2] + cache[i-1][3]) % d;
        }
        
    }
    answer = (cache[n][0] + cache[n][1] + cache[n][2] + cache[n][3]) % d;
    return answer;
}