#include <iostream>
#include <queue>

using namespace std;
int x;
queue<int> q;
int main(){
	int ans = 1;
	cin >> x;
	while (x != 1){
		if (x & 1) ans++;
		x /= 2;
	}
	cout << ans;
}
