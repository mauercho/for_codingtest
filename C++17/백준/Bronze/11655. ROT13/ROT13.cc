#include <bits/stdc++.h>

using namespace std;

string str;

int main(){
	getline(cin, str);
	for (auto i : str){
		if ('a' <= i && i <= 'z'){
			cout << char((i - 'a' + 13) % 26 + 'a');
		}
		else if ('A' <= i && i <= 'Z'){
			cout << char((i - 'A' + 13) % 26 + 'A');
		}
		else {
			cout << i;
		}
	}
}
