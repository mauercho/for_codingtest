#include <iostream>
#include <string>

using namespace std;
string a, b;
int main(){
	cin >> a >> b;
	string ans = "";
	int aSize = a.size() - 1; // 차피 10000 언저리임.
	int bSize = b.size() - 1;
	int flag = 0;
	int aNum, bNum;
	char alpha;
	while (aSize != -1 || bSize != -1){
		aNum = 0;
		bNum = 0;
		if (aSize != -1){
			aNum = a[aSize] - '0';
			aSize--;
		}
		if (bSize != -1){
			bNum = b[bSize] - '0';
			bSize--;
		}
		int sum_val = aNum + bNum + flag;
		if (sum_val >= 10){
			flag = 1;
			alpha = (sum_val % 10) + '0';
		}
		else {
			flag = 0;
			alpha = sum_val + '0';
		}
		ans = alpha + ans;
	}
	if (flag) ans = '1' + ans;
	for (char z: ans) cout << z;
	return 0;
}
