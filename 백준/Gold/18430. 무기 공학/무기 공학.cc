#include <array>
#include <iostream>
#include <vector>
using namespace std;


int arr[6][6];
bool visited[6][6];
vector<vector<array<int, 3>>> shapes = {
    {
        {0, 0, 2},
        {1, 0, 1},
        {0, -1, 1}
    },
    {
        {0, 0, 2},
        {-1, 0, 1},
        {0, -1, 1}
    },
    {
        {0, 0, 2},
        {-1, 0, 1},
        {0, 1, 1}
    },
    {
        {0, 0, 2},
        {1, 0, 1},
        {0, 1, 1}
    }
};
int n, m;
bool oob(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

int solve(int pos){
    if (pos == n *m)
        return 0;
    int x = pos / m;
    int y = pos % m;
    int ret = solve(pos+1);
    for (int i = 0; i < 4; i++)
    {
        bool isOOB = false;
        for (auto shape : shapes[i])
        {
            int nx = x + shape[0];
            int ny = y + shape[1];
            int nw = shape[2];
            if (oob(nx, ny) || visited[nx][ny]){
                isOOB =true;
                break;
            }
            
        }
        if (isOOB)
            continue;
        int cal = 0;
        for (auto shape : shapes[i])
        {
            int nx = x + shape[0];
            int ny = y + shape[1];
            int nw = shape[2];
            visited[nx][ny] = 1;
            cal += arr[nx][ny] * nw;
        }
        ret = max(ret, solve(pos+1) + cal);
        for (auto shape : shapes[i])
        {
            int nx = x + shape[0];
            int ny = y + shape[1];
            int nw = shape[2];
            visited[nx][ny] = 0;
        }
        
    }
    
    return ret;

}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    int ret = solve(0);
    cout << ret;

    return 0;
}