#include <bits/stdc++.h>

char alpha[26];

using namespace std;
int main(){
	int num;
	string str;
	cin >> num;
	string a;
	for (int i = 0; i < num; i++){
		cin >> str;
		alpha[str[0] - 'a'] += 1;
		if (alpha[str[0] - 'a'] == 5)
		{
			a += str[0];
		}
	}

	if (a.size() == 0)
		cout << "PREDAJA";
	else{
		sort(a.begin(), a.end());
		cout << a;
	}
}
