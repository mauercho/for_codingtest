#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;
string s;
vector<vector<int>> vec(21);
vector<vector<int>> copy_vec;
int ans = 987654321;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		for (int j = 0; j < n; j++) vec[i].push_back(s[j]);
	}
	for (int num = 0; num < (1 << n); num++){
		int temp_sum = 0;
		copy_vec = vec;
		for (int pos = 0; pos < n; pos++){
			if (num & (1 << pos)){ // 이 부분만 바꿀거임. vec[]
				for (int i = 0; i < n; i++){
					if (copy_vec[pos][i] == 'H') copy_vec[pos][i] ='T';
					else copy_vec[pos][i] = 'H';
				}
			}
		}
		for (int i = 0; i < n; i++){
			int t = 0;
			for (int j = 0; j < n; j++){
				if (copy_vec[j][i] == 'T') t += 1;
			}
			temp_sum += min(n - t, t);
		}
		ans = min(temp_sum, ans);
	}
	cout << ans;
}
