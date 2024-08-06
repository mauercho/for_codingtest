#include <bits/stdc++.h>

using namespace std;

string str;

int main(){
	cin >> str;

	int length = str.size();
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length -1 -i]){
			cout << 0;
			exit(0);
		}
	}
	cout << 1;
}
