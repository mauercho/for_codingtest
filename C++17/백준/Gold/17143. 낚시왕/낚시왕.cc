#include <iostream>
#include <map>

using namespace std;
struct elements {
	int e_s;
	int e_d;
	int e_z;
};
map<pair<int, int>, elements> mp;
map<pair<int, int>, elements> cp;
pair<int, int> directions[4] = {{-1,0}, {1,0}, {0, 1}, {0, -1}}; // 상, 하, 우, 좌
int r, c, m;

int check(int pos){
	int sum = 0;
	for (int i = 0; i < r; i++){
		if (mp.find({i, pos}) != mp.end()){
			sum = mp[{i, pos}].e_z;
			mp.erase({i, pos});
			break;
		}
	}
	return sum;
}

void shark_move() {
    cp.clear();
    for (auto temp : mp) {
        int i = temp.first.first;
        int j = temp.first.second;
        int s = temp.second.e_s;
        int d = temp.second.e_d;
        int z = temp.second.e_z; // 현재꺼 받음
		int ni = i, nj = j, nd = d;
		if (d == 0 || d == 1){ // 상 하
			int cycle = (r - 1) * 2;
			int end = s % cycle;
			for (int cnt = 0; cnt < end; cnt++){
				if (nd == 0 && ni == 0){
					nd = 1;
				}
				else if (nd == 1 && ni == r - 1){
					nd = 0;
				}
				ni = ni + directions[nd].first;
				nj = nj + directions[nd].second;
			}
		}
		else if (d == 2 || d == 3){
			int cycle = (c - 1) * 2;
			int end = s % cycle;
			for (int cnt = 0; cnt < end; cnt++){
				if (nd == 2 && nj == c){
					nd = 3;
				}
				else if (nd == 3 && nj == 1){
					nd = 2;
				}
				ni = ni + directions[nd].first;
				nj = nj + directions[nd].second;
			}
		}
		if (cp.find({ni, nj}) != cp.end()){ // 있으면
			if (cp[{ni, nj}].e_z < z){
				cp[{ni, nj}] = {s, nd, z};
			}
		}
		else {
			cp[{ni, nj}] = {s, nd, z};
		}
    }
	mp = cp;
}

int main(){
	int sum = 0;
	cin >> r >> c >>m;
	for (int i = 0; i < m; i ++){
		int a, b, s, d, z; // 속력, 이동방향, 크기
		cin >> a >> b >> s >> d >> z;
		mp[{a - 1, b}] = {s, d - 1, z};
	} // 구조체 씀. 이걸로 계속 이동할 예정
	int pos = 0; //  방향 전환 해야함.구분 잘해야함.
	while (pos < c){
		pos++;
		sum += check(pos);
		shark_move();
	}
	cout << sum;
	return 0;
}
