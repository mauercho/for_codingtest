#include <iostream>
#include <vector>

using namespace std;

int v[104];
int dices[10];
vector<int> adj[54];
int mal[4];
int ans = 0;
void add(int here, int there){
	adj[here].push_back(there);
}

void map_set(){
	for (int i = 0; i < 20; i++){ // 19 랑 20 이랑 까지 연결.
 		add(i, i + 1);
	}

	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(24, 25); add(25, 26); add(26, 20); add(20, 50);
	add(10, 27); add(27, 28); add(28, 24); add(15, 29);
	add(29, 30); add(30, 31); add(31, 24);
	v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10;
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
	v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25; v[25] = 30;
	v[26] = 35; v[27] = 22; v[28] = 24; v[29] = 28; v[30] = 27;
	v[31] = 26;
}


int move(int temp_idx, int num){
	if (temp_idx == 50) return 50;
	int cnt = dices[num];
	if (adj[temp_idx].size() > 1){
		temp_idx = adj[temp_idx][1];
		cnt--;
	}
	while (cnt > 0 && temp_idx != 50){
		temp_idx = adj[temp_idx][0];
		cnt--;
	}
	return temp_idx;
}

bool checkMal(int next_idx, int idx) {
    if (next_idx == 50) return false;
    for (int i = 0; i < 4; i++) {
        if (i == idx) continue;
        if (mal[i] == next_idx) return true;
    }
    return false;
}

int dfs(int num){
	if (num == 10) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++){
		int temp_idx = mal[i];
		int next_idx = move(temp_idx, num);
		if (checkMal(next_idx, i)) continue;
		mal[i] = next_idx;
		ret = max(ret, v[next_idx] + dfs(num + 1));
		mal[i] = temp_idx;
	}
	return ret;
}

int main() {
	for (int i = 0; i < 10; i++){
		cin >> dices[i];
	}
	map_set();
	int answer = dfs(0);

	cout << answer;
	return 0;
}
