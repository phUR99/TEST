#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int temp;
    vector<int> set;
    for (int i=1; i <=number; i++){
        temp =0;
        for(int j=1; j<sqrt(i); j++){          
            if(i % j ==0) temp++;         
        }
        temp *=2;
        if(sqrt(i)==(int)sqrt(i)) temp++;
        set.push_back(temp);
    }
    for (auto i : set){
        if (i > limit) answer += power;
        else answer +=i;
    }
    
    return answer;
}