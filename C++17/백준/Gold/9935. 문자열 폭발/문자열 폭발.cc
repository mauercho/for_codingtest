#include <string>
#include <iostream>
#include <stack>
using namespace std;

string s, t, temp;

int main(){
	cin >> s;
	cin >> t;
	for (char a: s){
		temp += a;
		if (temp.size() >= t.size() && temp.substr(temp.size() - t.size(), t.size()) == t){
			temp.erase(temp.end() - t.size(), temp.end());
		}
	}
	if (temp == "")
		cout << "FRULA";
	else{
		cout << temp;
	}
}
