#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k;
int visited[101];
int cnt[101];
int temp, full, ans;
vector<int> vec;
vector<int> used;

int minVal;
priority_queue<int, vector<int>, greater<int>> pq[101]; // 인덱스 제일 큰 놈 찾는 용도
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> k;
	int flag;
	for (int i = 0; i < k; i++){
		cin >> temp;
		cnt[temp] += 1;
		pq[temp].push(i);
		vec.push_back(temp);
	}
	for (int i = 0; i < k; i++){
		if (full < n){ // 그냥 막 꽂아.
			if (visited[vec[i]])
			{
				cnt[vec[i]] -= 1;
				continue;
			}
			visited[vec[i]] = 1;
			cnt[vec[i]] -= 1;
			full += 1;
			used.push_back(vec[i]);
		}
		else { // 다 차 있음.
			if (visited[vec[i]]) {
				cnt[vec[i]] -= 1;
				continue;
			} // 얘는 그냥 넘어가도 되는 친구 콘센트에 이미 뽑혀져 있음.
			else {
				flag = 0;
				// 첫 빠따로 cnt check
				minVal = 0;
				for (int j = 0; j < used.size(); j++){
					if (cnt[used[j]] == 0){ // 얘는 이제 나올 일이 없음. ㅇㅇ
						ans += 1;
						visited[used[j]] = 0;
						used.erase(used.begin() + j);
						flag = 1;
						visited[vec[i]] = 1;
						cnt[vec[i]] -= 1;
						used.push_back(vec[i]);
						break;
					}
					while (pq[used[j]].size() && pq[used[j]].top() < i){
						pq[used[j]].pop();
					}
					minVal = max(minVal, pq[used[j]].top()); // used 중에 최고 인덱스인거 뽑는 작업.
				}
				if (flag) continue;
				// 여기서 minVal의 index 가 들어있음. 그거 빼면 됨.
				for (int j = 0; j < used.size(); j++){
					if (used[j] == vec[minVal]){
						ans += 1;
						visited[used[j]] = 0;
						used.erase(used.begin() + j);
						visited[vec[i]] = 1;
						cnt[vec[i]] -= 1;
						used.push_back(vec[i]);
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
