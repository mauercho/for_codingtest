#include <bits/stdc++.h>

using namespace std;

int n;
int m;

vector<string> split(const string &input, const string &d) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(d);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + d.size();
        end = input.find(d, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val = 1;
        cin >> m;
		cin.ignore();
        string s;
        map<string, int> mp;
        vector<string> h;
        for (int j = 0; j < m; j++) {
            getline(cin, s);
            h = split(s, " ");
            if (mp[h[1]]) {
                mp[h[1]] += 1;
            } else {
                mp[h[1]] = 1;
            }
        }
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            val *= (iter->second + 1);
        }
        cout << (val - 1) << "\n";
    }
}
