#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int T;
vector<int> v;
int temp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++){
		v.clear();
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		cin >> M;
		for (int j = 0; j < M; j++){
			cin >> temp;
			if (upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) == 0){
				cout << 0 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
	}
}
