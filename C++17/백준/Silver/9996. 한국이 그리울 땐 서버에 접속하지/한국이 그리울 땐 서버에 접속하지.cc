#include <bits/stdc++.h>

using namespace std;
int num;

string first, pre, suf, s;
int main(){
	cin >> num;
	cin >> first;
	int pos = first.find('*');
	pre = first.substr(0, pos);
	suf = first.substr(pos + 1);
	for (int i = 0; i < num; i++){
		cin >> s;
		if (pre.size() + suf.size() > s.size()){
			cout << "NE" << "\n";
		}
		else if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size(), s.size())){
			cout << "DA" << "\n";
		}
		else
			cout << "NE" << "\n";
	}
}
