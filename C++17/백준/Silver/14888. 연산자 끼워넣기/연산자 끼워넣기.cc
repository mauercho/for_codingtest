#include <iostream>

using namespace std;
int methods[4];
int n;
int num[12];
int max_val = -1000000000;
int min_val = 1000000000;

void calculate(int depth, int sum){
	if (depth == n - 1){
		max_val = max(max_val, sum);
		min_val = min(min_val, sum);
		return ;
	}
	for (int i = 0; i < 4; i++){
		if (methods[i] > 0){
			methods[i] -= 1;
			if (i == 0){
				calculate(depth + 1, sum + num[depth + 1]);
			}
			else if (i == 1){
				calculate(depth + 1, sum - num[depth + 1]);
			}
			else if (i == 2){
				calculate(depth + 1, sum * num[depth + 1]);
			}
			else {
				if (num[depth + 1] != 0){
					if (sum < 0){
						calculate(depth + 1, -1 * ((-sum) / num[depth + 1]));
					}
					else calculate(depth + 1, sum / num[depth + 1]);
				}
			}
			methods[i] += 1;
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	for (int i = 0; i< 4;i++){
		cin >> methods[i];
	}
	calculate(0, num[0]);
	cout << max_val << "\n";
	cout << min_val << "\n";
	return 0;
}
