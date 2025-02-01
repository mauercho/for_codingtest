#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = arr[0];
    int sum = arr[0];

    for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
    return 0;
}
