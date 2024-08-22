#include <bits/stdc++.h>

using namespace std;
 
string s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int isVPS = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> st;
		cin >> s;
		isVPS = 0;
		for (char mem : s) {
			if (st.size() == 0) {
				if (mem == ')') {
					isVPS = 1;
					break;
				}
				else {
					st.push(mem);
				}
			}
			else { 
				if (mem == '(') {
					st.push(mem);
				}
				else {
					if (st.top() == '(')
						st.pop();
					else {
						isVPS = 1;
						break;
					}
				}
			}
		}
		if (st.size() > 0) {
			isVPS = 1;
		}
		if (isVPS == 1) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
}