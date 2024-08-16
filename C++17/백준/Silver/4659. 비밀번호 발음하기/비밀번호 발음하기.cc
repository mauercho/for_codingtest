#include <bits/stdc++.h>

using namespace std;


string s;
string vowel = "aeiou";
int main() {
	while (1) {
		int is_check = 1;
		int is_vowel = 0;
		int vowel_cnt = 0;
		int consonant_cnt = 0;
		stack<char> stk;
		cin >> s;
		if (!strcmp(s.c_str(), "end")) {
			break;
		}
		for (char alpha : s) {
			if (stk.size() == 0)
				stk.push(alpha);
			else {
				if (stk.top() != alpha) {
					stk.pop();
					stk.push(alpha);
				}
				else {
					if (!(alpha == 'o' || alpha == 'e')) {
						is_check = 0;
						break ;
					}
				}
			}

			if (vowel.find(alpha) != string::npos) { //모음일때
				is_vowel = 1;
				if (consonant_cnt >= 0) {
					vowel_cnt += 1;
					consonant_cnt = 0;
				}
				if (vowel_cnt == 3) {
					is_check = 0;
					break;
				}
			}
			else { //자음일때
				if (vowel_cnt >= 0) {
					consonant_cnt += 1;
					vowel_cnt = 0;
				}
				if (consonant_cnt == 3) {
					is_check = 0;
					break;
				}
			}
			
		}
		if (!is_check || is_vowel == 0) {
			cout << "<" << s << ">" << " is not acceptable.\n";
		}
		else {
			cout << "<" << s << ">" << " is acceptable.\n";
		}
	}
}