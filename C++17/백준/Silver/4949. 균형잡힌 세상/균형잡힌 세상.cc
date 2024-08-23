#include <bits/stdc++.h>

using namespace std;

string s;
string check = "[]()";
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, s);
	while (strcmp(s.c_str(), ".") != 0){
		stack<char> stk;
		bool isVPS = 1;
		for (char alpha: s){
			if (alpha == '[' || alpha == '('){
				stk.push(alpha);
			}
			else if (alpha == ')'){
				if (stk.size() == 0){
					isVPS = 0;
					break;
				}
				if (stk.top() == '('){
					stk.pop();
				}
				else {
					isVPS = 0;
					break;
				}
			}
			else if (alpha == ']'){
				if (stk.size() == 0){
					isVPS = 0;
					break;
				}
				if (stk.top() == '['){
					stk.pop();
				}
				else {
					isVPS = 0;
					break;
				}
			}
		}

		if (stk.size() != 0){
			isVPS = 0;
		}
		if (isVPS == 0){
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
		getline(cin, s);
	}
}
