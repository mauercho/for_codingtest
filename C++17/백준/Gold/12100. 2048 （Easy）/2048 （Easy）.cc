#include <iostream>
#include <cstring>
using namespace std;

int n;
int ret = 0;

void rotate(int (&arr)[21][21]) {
    int temp1[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp1[i][j] = arr[n - j - 1][i];
        }
    }
    memcpy(arr, temp1, sizeof(temp1));
}

void move(int (&arr)[21][21]) {
    int temp[21][21];
    for (int i = 0; i < n; i++) {
        int c = -1;
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) continue;
            else if (flag && arr[i][j] == temp[i][c]) flag = 0, temp[i][c] *= 2;
            else temp[i][++c] = arr[i][j], flag = 1;
        }
        for (int j = c + 1; j < n; j++) {
            temp[i][j] = 0;
        }
    }
    memcpy(arr, temp, sizeof(temp));
}

void dfs(int cnt, int (&arr)[21][21]) {
    if (cnt == 5) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num = max(num, arr[i][j]);
            }
        }
        ret = max(ret, num);
        return;
    }

    int original[21][21];
    memcpy(original, arr, sizeof(original));

    for (int i=0; i<4; i++) {
        int temp[21][21];
        memcpy(temp, original, sizeof(temp));

        for(int j=0; j<i; j++) rotate(temp);

    	move(temp);
    	dfs(cnt+1, temp);
	}
}

int main() {
    cin >> n;
    int arr[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, arr);
    cout << ret;
    return 0;
}
