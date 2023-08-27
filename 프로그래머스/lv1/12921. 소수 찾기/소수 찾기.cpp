#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num[n+1];
    for(int i=2; i<=n; i++){
        num[i] =i;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        
        if (num[i] == 0)
            continue;
        
        for (int j = i * i; j <= n; j += i)
            num[j] = 0;
    }
    for(int i=2; i<=n; i++){
        if(num[i] !=0) answer++;
    }
    
    return answer;
}