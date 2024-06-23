#include <string>
#include <vector>
#include <string.h>

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