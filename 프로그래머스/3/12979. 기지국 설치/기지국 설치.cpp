#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    stations.push_back(n+w+1);
    int e = 0;
    for (int s : stations){
        int d = max(0, s-w-1-e);
        answer += (d) / (2*w+1) + (d %(w*2+1) !=0);
        e = s+w;
    }

    return answer;
}