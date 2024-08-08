#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
	int cnt = 0;
	string temp;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> temp;
		vector<char> h;
 		bool isTrue = 1;
		for (char mem : temp){
			if (h.size() == 0){
				h.push_back(mem);
			}
			else {
				if (h[h.size() - 1] == mem){
					while (h[h.size() - 1] == mem)
						h.pop_back();
				}
				else {
					h.push_back(mem);
				}
			}
		}
		if (h.size() == 0) {
			cnt += 1;
		}
	}
	cout << cnt;
}
