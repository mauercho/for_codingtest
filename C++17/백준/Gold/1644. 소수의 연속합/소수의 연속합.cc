#include <iostream>
#include <vector>
#include <cmath>

// 에라토스테네스 체 외우기.
using namespace std;
int n;
bool isPrime[4000001];
vector<int> v;

int main(){
	int cnt = 0;
	isPrime[1] = false;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	fill(isPrime, isPrime + n + 1, true);
	for (int i = 2; i * i <= n; i++){
		if (isPrime[i]){
			for (int j = i * i; j <= n ; j+= i){
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) if (isPrime[i]) v.push_back(i); // 여기까지 n 이하의 소수들 모두 담았음.
	int start = 0;
	int end = 0;
	int sum = v[start];
	while (start <= end && end < v.size()){
		if (sum == n){
			cnt++;
			end++;
			if (end < v.size()) sum += v[end];
		}
		else if (sum > n){
			sum -= v[start];
			start++;
		}
		else {
			end++;
			if (end < v.size()) sum += v[end];
		}
	}
	cout << cnt;
	return 0;
}
