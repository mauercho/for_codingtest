#include <iostream>
#include <string>
#include <deque>

using namespace std;
int T, n, flag = 1; // flag 1이면 정방향.
string s, input;
deque<int> q;
int num;
int main(){
	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> s >> n >> input;
		num = 0;
		int correct = 0;
		q.clear();
		flag = 1;
		if (n != 0){
			for (char alpha : input){
				if (alpha == '[') continue;
				if (alpha == ']'){
					q.push_back(num);
					break ;
				}
				if (alpha == ','){
					q.push_back(num);
					num = 0;
				}
				else {
					num = num * 10 + (alpha - '0');
				}
			}
		}
		for (char alpha: s){
			if (alpha == 'D'){
				if (q.size() > 0){
					if (flag == 1){
						q.pop_front();
					}
					else {
						q.pop_back();
					}
				}
				else {
					correct = 1;
					break;
				}
			}
			else flag *= -1;
		}
		if (correct) cout << "error\n";
		else {
			cout << "[";
			if (flag == 1){ // 정방향.
				for (int i = 0; i < q.size(); i++){
					cout << q[i];
					if (i != q.size() - 1) cout << ",";
				}
			}
			else {
				for (int i = q.size() - 1; i > -1; i--){
					cout << q[i];
					if (i != 0) cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}
