#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int x;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> vec;
	int temp;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> x;
	sort(vec.begin(), vec.end());
	int start = 0;
	int end = n - 1;
	while (end > start){
		int sum = vec[start] + vec[end];
		if (sum == x){
			cnt += 1;
			start += 1;
		}
		else if (sum < x){
			start += 1;
		}
		else {
			end -= 1;
		}
	}
	cout << cnt;
}
