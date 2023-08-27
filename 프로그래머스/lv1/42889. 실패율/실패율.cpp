#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> set;
    double temp;
    double users = stages.size();
    sort(stages.begin(), stages.end());
    for (int i=1; i <= N; i++){
        temp=0;
        for(auto j :stages){
            if (i==j) temp++;            
        }
        if(temp !=0)set.push_back(make_pair(temp/users, i));           
        else set.push_back(make_pair(0, i));           
        users -=temp;
    }
    sort(set.begin(), set.end(), cmp);
    for (int i=0; i < set.size(); i++){
        answer.push_back(set[i].second);
    }
    
    return answer;
}