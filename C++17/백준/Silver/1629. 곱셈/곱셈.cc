#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
ll a, b, c;

ll recur(ll n, ll div){
	ll temp;
	if (div == 1){
		return (n % c);
	}
	temp = recur(n, div / 2);
	temp = (temp * temp) % c;
	if (div % 2){
		temp = (temp * n) % c;
	}
	return temp;
}

int main(){
	cin >> a >> b >> c;
	cout << recur(a, b);
}
