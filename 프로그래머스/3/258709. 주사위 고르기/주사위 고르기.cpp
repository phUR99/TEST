#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> order;
vector<int> sum[300];
int arr[5];
int n;

void func(int cnt, int cur){
	if (cnt == n){
		vector<int> temp;
		for (int i = 0; i < n; i++)
		{
			temp.push_back(arr[i]);
		}
		order.push_back(temp);
		return;
	}
	for (int i = cur + 1; i < 2 *n; i++)
	{
		arr[cnt] = i;
		func(cnt+1, i);
	}	
}
void make(int order, int cnt, vector<vector<int>> &dice, vector<int> list){
	if (cnt == n){
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += dice[list[i]][arr[i]];
		}
		sum[order].push_back(temp);
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		arr[cnt] = i;
		make(order, cnt+1, dice, list);
	}
	

}

vector<int> solution(vector<vector<int>> dice) {
    
	vector<int> answer;


	n = (int)dice.size() / 2;

	int exp = 1;
	bool choose[10];
	vector<int> B;
	func(0, -1);


	for (int i = 0; i < n; i++)
	{
		exp *= 6;
	}
	

	for (int i =0; i < order.size(); i++)
	{	
		make(i, 0, dice, order[i]);
		sort(sum[i].begin(), sum[i].end());
	}

	int max_win = 0;
	int max_ord = 0;

	for (int i =0; i < order.size(); i++)
	{	
		memset(choose, false, sizeof(choose));
		B.clear();

		for (auto number : order[i])
		{				
			choose[number] = true;
		}	
			
		for (int j = 0; j < 2 *n; j++)
		{
			if(!choose[j])	B.push_back(j);
		}

		int b_ord = 0;
		for (int j = 0; j < order.size(); j++)
		{			
			bool flag = false;
			for (int k = 0; k < n; k++)
			{
				int number_1 = order[j][k];
				int number_2 = B[k];
				if(number_1 != number_2) {
					flag = true;
					break;
				}				
			}
			if(flag) continue;
			b_ord = j;
			break;			
		}
		int win = 0;
		for (int j = 0; j < exp; j++)
		{
			int node = sum[i][j];
			int temp = upper_bound(sum[b_ord].begin(), sum[b_ord].end(), node-0.1) - sum[b_ord].begin();
			win += temp;
		}
		if(win > max_win){
			max_win = win;
			max_ord = i;
		}		
		
	}
	for (int i = 0; i < n; i++)
	{
		answer.push_back({order[max_ord][i]+1});
	}
	return answer;
    
}