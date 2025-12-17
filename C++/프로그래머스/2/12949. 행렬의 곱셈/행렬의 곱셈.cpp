#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int n = arr1.size();
    int a = arr1[0].size();
    int m = arr2[0].size();
    answer.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int sum_val = 0;
            for (int z = 0; z < a; z++){
                sum_val += arr1[i][z] * arr2[z][j];
            }
            answer[i][j] = sum_val;
        }
    }
    
    return answer;
}