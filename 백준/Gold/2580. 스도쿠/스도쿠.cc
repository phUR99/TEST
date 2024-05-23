#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int>> zero;

void func(vector<pair<int, int>>::iterator iter){
    if(iter == zero.end()){
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    int row = iter->first;
    int col = iter->second;
    bool check[10] ={false};    

    for (int i = 0; i < 9; i++)
    {
        check[board[row][i]] = true;
        check[board[i][col]] = true;
    }
    int r_idx = row / 3;
    int c_idx = col / 3;
    for (int i = r_idx * 3; i < (r_idx+1) * 3; i++)
    {
        for (int j = c_idx*3; j < (c_idx + 1) * 3; j++)
        {            
            check[board[i][j]] = true;
        }        
    }
    for (int i = 1; i < 10; i++)
    {
        if(check[i]) continue;
        board[row][col] = i;  
        //백트래킹이므로 iter가 증가한 후 다시 반환되어야 한다는 것에 유의 iter++, ++iter -> 사용 X      
        func(iter+1);        
        board[row][col] = 0;        
    }
    
    

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0){
                zero.push_back({i, j});
            }
        }
        
    }
    func(zero.begin());


    return 0;
}