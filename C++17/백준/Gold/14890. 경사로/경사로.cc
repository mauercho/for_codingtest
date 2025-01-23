#include <iostream>


using namespace std;

int N, L;
int arr[101][101];
int ans;
int check_row(int a){
    int cnt = 1;
    int num = arr[a][0];
    bool slope[101] = {false};  // 경사로 설치 여부 체크
    for (int j = 1; j < N; j++){
        if (num == arr[a][j]){
            cnt++;
        }
        else if (num - arr[a][j] == 1){ // 내리막
            if (j + L > N) return 0;
            for (int t = 0; t < L; t++){
                if (arr[a][j] != arr[a][j+t] || slope[j+t]) return 0;
                slope[j+t] = true;
            }
            num = arr[a][j];
            j = j + L - 1;
            cnt = 0;
        }
        else if (arr[a][j] - num == 1){ // 오르막
            if (cnt < L) return 0;
            for (int t = 1; t <= L; t++){
                if (slope[j-t]) return 0;
                slope[j-t] = true;
            }
            num = arr[a][j];
            cnt = 1;
        }
        else return 0;
    }
    return 1;
}


int check_col(int a){
    int cnt = 1;
    int num = arr[0][a];
    bool slope[101] = {false};  // 경사로 설치 여부 체크
    for (int j = 1; j < N; j++){
        if (num == arr[j][a]){
            cnt++;
        }
        else if (num - arr[j][a] == 1){ // 내리막
            if (j + L > N) return 0;
            for (int t = 0; t < L; t++){
                if (arr[j][a] != arr[j+t][a] || slope[j+t]) return 0;
                slope[j+t] = true;
            }
            num = arr[j][a];
            j = j + L - 1;
            cnt = 0;
        }
        else if (arr[j][a] - num == 1){ // 오르막
            if (cnt < L) return 0;
            for (int t = 1; t <= L; t++){
                if (slope[j-t]) return 0;
                slope[j-t] = true;
            }
            num = arr[j][a];
            cnt = 1;
        }
        else return 0;
    }
    return 1;
}



int main(){
	cin >> N >> L;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < N; i++){
		if (check_row(i)) ans += 1;
	}
	for (int i =0; i< N; i++){
		if (check_col(i)) ans += 1;
	}
	cout << ans;
}
