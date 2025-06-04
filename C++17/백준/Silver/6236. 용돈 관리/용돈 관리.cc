#include <iostream>
#include <vector>

int n, m;

using namespace std;
vector<int> v;

bool check(int num){
	int cnt = 1;
	int ref = num;
	for (int i = 0; i < v.size(); i++){
		if (num < v[i]) return false;
		if (ref - v[i] >= 0) ref -= v[i];
		else {
			cnt += 1;
			ref = num - v[i];
		}
	}
	return cnt <= m;
}

int main() {
	cin >> n >> m;
	int l = 1e9;
	int temp;
	int r = 0;
	int ret;
	for (int i = 0; i < n; i++){
		cin >> temp;
		r += temp; // 이건 합산 값.
		if (l > temp){
			l = temp; // 최솟 값으로 가져가기.
		}
		v.push_back(temp);
	}
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){

			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
	return 0;
}
