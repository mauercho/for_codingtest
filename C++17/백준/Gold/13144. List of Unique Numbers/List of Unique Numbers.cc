#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
bool visited[100001];
ll arr[100001];
ll n;
ll result;
ll start;
ll last;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (start < n){
		while (last < n && !visited[arr[last]]){
			visited[arr[last]] = true;
			last++;
		}

		result += (last - start);
		visited[arr[start]] = false;
		start++;
	}
	cout << result;
	return 0;
}
