#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //내림차순으로 벡터 정렬하기
    sort(citations.begin(), citations.end(), greater<int>());
    //최댓값이 0이면 답은 0
    if (!citations[0])        return 0;
    
    for (int i = 0; i < citations.size(); i++)    {
        // 원소가 idx 범위 안이라면
        if (citations[i] > i)    answer++;
        // 아니면 중단
        else    break;
    }
    return answer;
}