#include <vector>

using namespace std;
int chk(int n){
    int cnt=0;
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
                if(chk(nums[i]+nums[j]+nums[k]))answer++;
                
            }        
        }
    }
   
    return answer;
}