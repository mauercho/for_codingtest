#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
map<int, int> isprime;

double answer = 1;
double sumVal1 = 0;
double sumVal2 = 0;
int a, b;

void calc(double pos, int round, int goals, double totalPos){
	if (round == 18){
		if (!isprime[goals]){
			sumVal1 += totalPos;
		}
		return;
	}
	calc(pos, round + 1, goals, totalPos * (1 - pos)); // 골 못 넣음.
	calc(pos, round + 1, goals + 1, totalPos * pos);
}

void calc2(double pos, int round, int goals, double totalPos){
	if (round == 18){
		if (!isprime[goals]){
			sumVal2 += totalPos;
		}
		return;
	}
	calc2(pos, round + 1, goals, totalPos * (1 - pos)); // 골 못 넣음.
	calc2(pos, round + 1, goals + 1, totalPos * pos);
}


int main(){
	cout << fixed << setprecision(9);
	isprime[2] = isprime[3] = isprime[5] = isprime[7] = isprime[11] = isprime[13] = isprime[17] = 1;

	cin >> a >> b;
	calc((double)a / 100, 0, 0, 1);
	calc2((double)b / 100, 0, 0, 1);
	cout << 1 - sumVal1 * sumVal2;
	return 0;
}
