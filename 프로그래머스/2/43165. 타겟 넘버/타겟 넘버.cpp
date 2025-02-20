#include <string>
#include <vector>

using namespace std;

bool solve(int s, vector<int> &arr, int t){
    int ret = 0;
    for(int i =0; i < arr.size(); i++){
        if((1<<i) & s)
            ret += arr[i];
        else
            ret -= arr[i];
    }
    return ret == t;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    int full_bit = (1<<n)-1;
    for(int state = full_bit; state >=0; state--){
        if(solve(state, numbers, target)) answer++;
    }
    return answer;
}