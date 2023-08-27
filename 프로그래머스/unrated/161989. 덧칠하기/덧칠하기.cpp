#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int temp=0;
    
    for(auto i : section){
        if(temp > i) continue;
        answer++;
        temp =m+i;
    }
    return answer;
}