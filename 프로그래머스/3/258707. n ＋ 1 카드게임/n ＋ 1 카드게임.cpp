#include <string>
#include <vector>
#include <string.h>

using namespace std;



int solution(int coin, vector<int> cards) {

    int answer = 0;
    int n = (int)cards.size();    
    bool used[1005] = {false};
    bool canuse[1005] = {false};

    int life = 0;
    
    for (int i = 0; i < n/3; i++)
    {
        canuse[cards[i]] = true;
        if(canuse[n +1 - cards[i]]) {
            life++;            
            used[n+1-cards[i]] = true;
            used[cards[i]] = true;
        }
    }    
    for (int i = n/3 + 1; i < n; i+=2)
    {        
        bool flag = false;        
        canuse[cards[i]] = true;
        canuse[cards[i-1]] = true;
        if (life >= (i-n/3+1)/2) continue;

        if (coin < 1) break;
        for (int j = 0; j < n/3; j++)
        {
            if(canuse[n+1 - cards[j]] && !used[cards[j]]){
                used[n+1-cards[j]] = true;
                used[cards[j]] = true;
                coin--;
                flag = true;
                life++;
                break;
            }
        }    
        if(flag) continue;

        if (coin < 2) break;
        for (int j = i; j >= n/3; j--)
        {
            if(canuse[n+1-cards[j]] && !used[cards[j]]){
                used[n+1-cards[j]] = true;
                used[cards[j]] = true;
                coin -=2;
                life++;
                flag = true;
                break;
            }
            
        }
        if(flag) continue;       
        break;
    }        
    
    if(life >= n/3 && coin){
        for (int i = 0; i < n/3; i++)
        {
            if(!used[cards[i]] && coin){
                coin--;
                life++;
                used[cards[i]] = true;
                used[n+1-cards[i]] = true;
            }                        
        }
        for (int i = n/3; i < n; i++)
        {
            if(!used[cards[i]] && coin >=2){
                coin -=2;
                life++;
                used[cards[i]] = true;
                used[n+1-cards[i]] = true;
            }
        }
        
    }
    answer = min(n/3, life) + 1;
    
    return answer;
}


