#include <iostream>
#include <vector>

using namespace std;
int n, m;
int l = 1, r;
int answer;
vector<int> v;
// 크면 성공 가능성 업 작으면 작아짐.

bool check(int num){
	int ret = 0;
	for (auto mem: v){
		ret += (mem / num);
		if (mem % num != 0){
			ret += 1;
		}
	}
	return ret <= n;
}

int main(){
	cin >> n >> m;
	int temp;
	for (int i = 0; i < m; i++){
		cin >> temp;
		if (temp > r){
			r = temp;
		}
		v.push_back(temp);
	}
	answer = r;
	while (l <= r){
		int middle = (l + r) / 2;
		if (check(middle)) {
			r = middle - 1;
			answer = middle;
		}
		else {
			l = middle + 1;
		}
	}
	cout << answer;
	return 0;
}
