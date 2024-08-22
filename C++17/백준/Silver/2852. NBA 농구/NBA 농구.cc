#include <bits/stdc++.h>

using namespace std;
int t;
string s;
int team;
int total_time = 48 * 60;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int prev_win = -1;
	int score_one = 0;
	int score_two = 0;
	int time_one = 0;
	int time_two = 0;
	int start_time = 0;
	int time;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> team;
		if (team == 1) {
			score_one += 1;
		}
		else
			score_two += 1;
		cin >> s;
		time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
		if (score_one > score_two) {
			if (prev_win == -1) { // 전에 무승부 였을 경우
				prev_win = 0;
				start_time = time;
			}
			else { 
				time_one += (time - start_time);
				start_time = time;
			}
		}
		else if (score_two > score_one) {
			if (prev_win == -1) { // 전에 무승부 였을 경우
				prev_win = 1;
				start_time = time;
			}
			else { // prev_win 
				time_two += (time - start_time);
				start_time = time;
			}
		}
		else { // 무승부임.
			if (prev_win == 0) {
				time_one += (time - start_time);
			}
			else if (prev_win == 1){
				time_two += (time - start_time);
			}
			start_time = time;
			prev_win = -1;
		}
	}
	if (start_time != total_time) {
		if (score_one > score_two) {
			time_one += (total_time - start_time);
		}
		else if (score_two > score_one) {
			time_two += (total_time - start_time);
		}
	}

	int one_hour = (time_one / 60);
	int one_minute = (time_one % 60);
	int two_hour = (time_two / 60);
	int two_minute = (time_two % 60);
	if (one_hour < 10) {
		cout << "0" << to_string(one_hour) << ":";
	}
	else {
		cout << to_string(one_hour) << ":";
	}
	if (one_minute < 10) {
		cout << "0" << to_string(one_minute) << "\n";
	}
	else {
		cout << to_string(one_minute) << "\n";
	}
	if (two_hour < 10) {
		cout << "0" << to_string(two_hour) << ":";
	}
	else {
		cout << to_string(two_hour) << ":";
	}
	if (two_minute < 10) {
		cout << "0" << to_string(two_minute) << "\n";
	}
	else {
		cout << to_string(two_minute) << "\n";
	}
}