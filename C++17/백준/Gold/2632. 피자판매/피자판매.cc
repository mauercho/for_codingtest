#include <iostream>
#include <map>
#include <vector>

int m, n;
int purpose;
using namespace std;
map<int, int> map_a, map_b;
vector<int> a, b;


void start_a(vector<int> tmp){
	int sz = tmp.size();
	for (int i = 0; i < sz; i++){
		int sum = 0;
		for (int j = 0; j < sz - 1; j++){
			sum += tmp[(i + j)% sz];
			if (map_a.find(sum) != map_a.end()){
				map_a[sum] += 1;
			}
			else {
				map_a[sum] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <sz; i++){
		sum += tmp[i];
	}
	if (map_a.find(sum) != map_a.end()){
		map_a[sum] += 1;
	}
	else {
		map_a[sum] = 1;
	}
}

void start_b(vector<int> tmp){
	int sz = tmp.size();
	for (int i = 0; i < sz; i++){
		int sum = 0;
		for (int j = 0; j < sz - 1; j++){
			sum += tmp[(i + j)% sz];
			if (map_b.find(sum) != map_b.end()){
				map_b[sum] += 1;
			}
			else {
				map_b[sum] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <sz; i++){
		sum += tmp[i];
	}
	if (map_b.find(sum) != map_b.end()){
		map_b[sum] += 1;
	}
	else {
		map_b[sum] = 1;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp;
	int ret = 0;
	cin >> purpose;
	cin >> m >> n;
	for (int i = 0; i< m; i++){
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i< n; i++){
		cin >> temp;
		b.push_back(temp);
	}
	// 여기 까지 하고 보기.
	start_a(a);
	start_b(b);

    for (auto mem : map_a) {
        int need = purpose - mem.first;
        if (map_b.find(need) != map_b.end()) {
            ret += mem.second * map_b[need];
        }
    }
	if (map_a.find(purpose) != map_a.end()){
		ret += map_a[purpose];
	}
	if (map_b.find(purpose) != map_b.end()){
		ret += map_b[purpose];
	}
	cout << ret;
}
