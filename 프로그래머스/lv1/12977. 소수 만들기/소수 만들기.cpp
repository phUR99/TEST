#include <vector>
// 소수를 어떻게 만들지에 대한 구현(chk)
// 주어진 nums에서 어떻게 3개의 원소를 모두 탐색할 지에 대한 구현
using namespace std;
int chk(int n){
    int cnt=0;
    // 소수의 약수는 항상 2이므로(1과 n) 약수의 개수가 2개를 넘어가면 소수가 아니라고 판단
    for(int i=1; i<=n; i++){
        if(n%i ==0) cnt++;
    }
    return (cnt >2) ? 0 : 1;
}


int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k=j+1; k<n; k++){
                // 3중 for문을 이용해서 3개의 원소를 완전 탐색으로 해결한다.
                if(chk(nums[i]+nums[j]+nums[k]))answer++;
                
            }        
        }
    }
   
    return answer;
}
