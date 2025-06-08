#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n, temp;
vector<int> v;
int main(){
	cin >> n;
	vector<int> lis;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
		auto it = lower_bound(lis.begin(), lis.end(),temp);
		int pos = it - lis.begin();
		if (it == lis.end()){
			lis.push_back(temp);
		} else {
			*it = temp;
		}
		p[i].first = pos;
		p[i].second = temp;
	}

	cout << lis.size() << "\n";
	int len = lis.size() - 1;
	stack<int> stk;
	for (int i = n - 1; i >= 0; i--){
		if (p[i].first == len){
			len--;
			stk.push(p[i].second);
		}
	}
	while (!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;
}
