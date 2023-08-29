#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//true 조건에 등호를 넣었을 때 나올 수 있는 문제
//compare 함수에서 계속 core dumped 에러가 났는데, 컴파일러 버전에 따라 비교로 들어온 두 인자가 같은 경우 true 를 반환하면 오류가 난다고 한다.
//https://stackoverflow.com/questions/1541817/sort-function-c-segmentation-fault
//케이스 11번이 계속 실패
//return에 "0"이 아닌 0을 주어서 나온 실패로 보인다
//값의 비교를 하기 위해서 int 대신 string으로 바꿔서 체크를 하는 것이 핵심
//두 문자를 더해서 string으로 비교한 후에 custom한 cmp를 sort에 줘서 정렬시키는 문제
using namespace std;
bool cmp(const string &a, const string &b)
{   
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = ""; 
    vector<string> temp;
    for (auto i : numbers){
        temp.push_back(to_string(i));
    }
    sort(temp.begin(), temp.end(), cmp);
    if (temp.at(0) == "0") return "0";
    for(auto i : temp){
        answer += i;
    }
    return answer;
}
