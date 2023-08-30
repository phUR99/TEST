#include <iostream>
#include <vector>
using namespace std;
vector<int> costVec;
vector<int> lenVec;

int main() {
	int N;
	cin >> N;
	int temp, minCost = 0;
	long long int sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		cin >> temp;
		lenVec.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		costVec.push_back(temp);
	}
	minCost = costVec[0];
	sum = minCost * lenVec[0];
	for (int i = 1; i < N-1; i++)
	{
		if (minCost <= costVec[i]) sum += minCost * lenVec[i];
		else {
			minCost = costVec[i];
			sum += lenVec[i] * minCost;
		}
		
		
	}
	cout << sum;
}