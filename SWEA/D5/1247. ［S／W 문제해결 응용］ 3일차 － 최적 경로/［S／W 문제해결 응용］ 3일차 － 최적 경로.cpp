#include<iostream>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
pair<int, int> arr[12];
int idx[12];
int N;
bool used[12];

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
int answer;
int solution(){
    int ret = 0;
    for (int i = 0; i < N+1; i++)
    {
        ret += dist(arr[idx[i]].first, arr[idx[i]].second, arr[idx[i+1]].first, arr[idx[i+1]].second);
    }
    return ret;
}
void possibleCase(int cnt){
    if(cnt == N + 1) {
        answer = min(answer, solution());
        return;
    }
    for (int i = 2; i < N + 2; i++)
    {
        if(used[i]) continue;
        used[i] = true;
        idx[cnt] = i;
        possibleCase(cnt+1);
        used[i] = false;
    }    
}


int main(int argc, char** argv)
{
    fastio;
	int test_case;
	int T;
	cin>>T;
    idx[0] = 0;
   
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        idx[N+1] = 1;
        answer = 987654321;
        for (int i = 0; i < N+2; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        possibleCase(1);
        cout << "#" << test_case << ' ';
        cout << answer << '\n';

	}
	return 0;
}