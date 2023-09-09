#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string str;
	stack<char> stack1;

	vector<string> vec;

	while (true) {
		getline(cin, str);
		int flag = 0;
		if (str[0] == '.') break;

		for(auto s : str)
		{
		
			if (s == '(') {
				stack1.push('(');

			}
			else if (s == ')') {
				if (stack1.empty()) {
					vec.push_back("no");
					flag = 1;
					break;
				}
				else {
					if (stack1.top() != '(') {
						vec.push_back("no");
						flag = 1;
						break;
					}
					stack1.pop();

				}
				
			}

			if (s == '[') {
				stack1.push('[');

			}
			else if (s == ']') {
				if (stack1.empty()) {
					vec.push_back("no");
					flag = 1;
					break;
				}
				else { 
					if (stack1.top() != '[') {
						vec.push_back("no");
						flag = 1;
						break;
					}
					stack1.pop(); 

				}
			}	
		}

		if (stack1.empty()&&flag==0) vec.push_back("yes");
		if (!stack1.empty()) if(flag==0) vec.push_back("no");

		while (!stack1.empty()) stack1.pop();
		
	}
	for (auto v : vec) {
		cout << v << '\n';
	}
}
