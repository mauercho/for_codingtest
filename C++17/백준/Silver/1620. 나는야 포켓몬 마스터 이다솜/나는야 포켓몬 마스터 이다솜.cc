#include <bits/stdc++.h>

using namespace std;

int m,n;
map<string, int> mp1;
map<int, string> mp2;
string str;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++)
	{
		cin >> str;
		mp1[str] = i;
		mp2[i] = str;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (str[0] >= '1' && str[0] <= '9')
			cout << mp2[atoi(str.c_str())]<< "\n";
		else
			cout << mp1[str]<< "\n";
	}
}
