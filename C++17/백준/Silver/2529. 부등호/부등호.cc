#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <string>

using namespace std;
typedef long long ll;
ll max_val = numeric_limits<ll>::min();
ll min_val = numeric_limits<ll>::max();
string s = "0123456789";
char arr[10];
int k;
int main(){
	int flag;
	cin >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	do {
		flag = 0;
		for (int i = 0; i < k; i++){
			if (arr[i] == '>'){
				if (s[i] < s[i + 1]) flag = 1;
			}
			else {
				if (s[i] > s[i + 1]) flag = 1;
			}
		}
		if (!flag) {
			ll num = stoll(s.substr(0, k + 1));
			max_val = max(max_val, num);
			min_val = min(min_val, num);
		}
	} while (next_permutation(s.begin(), s.end()));
	string s1 = '0' + to_string(max_val);
	string s2 = '0' + to_string(min_val);
	cout << s1.substr(s1.size() - (k + 1)) << "\n";
	cout << s2.substr(s2.size() - (k + 1));
}
