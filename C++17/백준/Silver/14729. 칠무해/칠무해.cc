#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
int n;
priority_queue<double> pq;

int main(){
	cin >> n;
	double temp;
	for (int k = 0; k < n; k++){
		cin >> temp;
		pq.push(-1.0 * temp);
	}
	cout << fixed <<setprecision(3);
	for (int i = 0; i < 7; i++){
		cout << -1.0 * pq.top() << "\n";
		pq.pop();
	}
}
