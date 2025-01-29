#include <iostream>
#include <stack>

typedef long long ll;
using namespace std;

ll n, ret, temp, cnt;
stack<pair<ll, ll>> s;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> temp;
		cnt = 1;
		while (s.size() && s.top().first <= temp){
			ret += s.top().second;
			if (s.top().first == temp){
				cnt = s.top().second + 1;
			}
			else {
				cnt = 1;
			}
			s.pop();
		}
		if (s.size() > 0) ret++;
		s.push({temp, cnt});
	}
	cout << ret;
	return 0;
}
