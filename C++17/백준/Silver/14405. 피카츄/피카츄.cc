#include <iostream>
#include <string>

using namespace std;
string s;
int main(){
	cin >> s;
	int flag = 0;
	int idx = 0;

	while (idx < s.size()){
		if (s[idx] == 'p')
		{
			if (s.substr(idx, 2) == "pi"){
				idx += 2;
			}
			else {
				flag = 1;
				break;
			}
		}
		else if (s[idx] == 'k')
		{
			if (s.substr(idx, 2) == "ka"){
				idx += 2;
			}
			else {
				flag = 1;
				break;
			}
		}
		else {
			if (s.substr(idx, 3) == "chu"){
				idx += 3;
			}
			else {
				flag = 1;
				break;
			}
		}
	}
	cout << (flag ? "NO": "YES");
	return 0;
}
