#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int m, num = 0;
    cin >> m;

    while (m--) {
        string s;
        int x;
        cin >> s;

        if (s == "add") {
            cin >> x;
            num |= (1 << (x - 1));
        } else if (s == "remove") {
            cin >> x;
            num &= ~(1 << (x - 1));
        } else if (s == "check") {
            cin >> x;
            cout << ((num & (1 << (x - 1))) ? "1\n" : "0\n");
        } else if (s == "toggle") {
            cin >> x;
            num ^= (1 << (x - 1));
        } else if (s == "all") {
            num = (1 << 21) - 1;
        } else num = 0;
    }

    return 0;
}
