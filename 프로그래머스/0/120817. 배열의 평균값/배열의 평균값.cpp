#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for (auto number : numbers){
        answer += number;
    }
    answer /= numbers.size();
    return answer;
}