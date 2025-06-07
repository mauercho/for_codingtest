#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int temp;
vector<int> v;
int main(){
	cin >> n;
	vector<int> lis;
	vector<int> p(n);
	for (int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
		auto it = lower_bound(lis.begin(), lis.end(), temp);
		int pos = it - lis.begin();
		if (it == lis.end()){
			lis.push_back(temp);
		} else {
			*it =temp;
		}
		p[i] = pos;
	}
	cout << lis.size() << "\n";
	vector<int> ans;
	int ref = lis.size() - 1;
	// for (auto mem: p) cout << mem << " ";
	for (int i = n - 1; i >= 0; i--){
		if (p[i] == ref){
			ans.push_back(v[i]);
			ref--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i] << " ";
	}
	return 0;
}
