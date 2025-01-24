#include <iostream>
#include <string>

using namespace std;

int n, k;
int words[51];
string s;

int countNum(int mask){
    int cnt = 0;
    for (auto word : words){
        if (word && (word & mask) == word) cnt++;
    }
    return cnt;
}

int dfs(int index, int k, int mask){
    if (k < 0) return 0;
    if (index == 26){
        return countNum(mask);
    }
    int ret = dfs(index + 1, k - 1, mask | (1 << index)); // 현재 알파벳 선택
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') ret = max(ret, dfs(index + 1, k, mask));
    return ret;
}

int main(){
    cin >> n >> k;
    int num;
    for (int i = 0; i < n; i++){
        cin >> s;
        num = 0;
        for (char alpha : s){
            num |= 1 << (alpha - 'a');
        }
        words[i] = num; // words에 숫자 담음.
    }
    cout << dfs(0, k, 0);
}
