#include <bits/stdc++.h>

using namespace std;

int n, k;
int temp;
int maxSum = -100000000;
int arr[100001];
int sum;
int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> temp;
		arr[i] = temp;
	}
	for (int i = 1; i <= n - k + 1; i++){
		sum = 0;
		for (int c = 0; c < k; c++){
			sum += arr[c + i];
		}
		if (maxSum < sum)
			maxSum = sum;
	}
	cout << maxSum;
}
