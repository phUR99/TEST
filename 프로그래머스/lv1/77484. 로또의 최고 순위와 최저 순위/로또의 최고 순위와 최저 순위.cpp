#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero=0, correct=0;
    for (auto i: lottos){
        if (i==0) zero++;
        else {
            for (auto j : win_nums){
                if (i==j) correct++;
            }
        } 
    }
    if (zero ==0 && correct ==0) answer.push_back(6);
    else answer.push_back(7-zero-correct);
    if (correct !=0) answer.push_back(7-correct);
    else answer.push_back(6);
    return answer;
}