#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int n;
vector<double> v;
int main(){
	cin >> n;
	double temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	double acc = 1;
	double ans = v[0];
	for (auto mem: v){
		acc = acc * mem;
		if (acc < mem){
			acc = mem;
		}
		ans = max(ans, acc);
	}
	cout << fixed << setprecision(3) << ans;
	return 0;
}
