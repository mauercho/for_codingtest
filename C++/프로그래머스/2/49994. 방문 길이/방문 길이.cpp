#include <string>
#include <set>
#include <iostream>
using namespace std;

int solution(string dirs) {
    set<string> st;
    int answer = 0;
    int prev_i = 0;
    int prev_j = 0;
    int next_i = 0;
    int next_j = 0;
    int t_i, t_j;
    string s;
    for (auto dir: dirs){
        if (dir == 'L'){
            t_i = prev_i - 1;
            t_j = prev_j;
            if (t_i > 5 || t_i < -5 || t_j > 5 || t_j < -5) continue;
            next_i = t_i;
            next_j = t_j;
            string path1 = to_string(prev_i) + to_string(prev_j) + to_string(next_i) + to_string(next_j);
            string path2 = to_string(next_i) + to_string(next_j) + to_string(prev_i) + to_string(prev_j);
            if (st.count(path1) || st.count(path2)){
                prev_i = next_i;
                prev_j = next_j;
            } else {
                st.insert(path1);
                st.insert(path2);
                answer += 1;
                prev_i = next_i;
                prev_j = next_j;
            }
            
        } else if (dir == 'R'){
            t_i = prev_i + 1;
            t_j = prev_j;
            if (t_i > 5 || t_i < -5 || t_j > 5 || t_j < -5) continue;
            next_i = t_i;
            next_j = t_j;
            string path1 = to_string(prev_i) + to_string(prev_j) + to_string(next_i) + to_string(next_j);
            string path2 = to_string(next_i) + to_string(next_j) + to_string(prev_i) + to_string(prev_j);
            if (st.count(path1) || st.count(path2)){
                prev_i = next_i;
                prev_j = next_j;
            } else {
                st.insert(path1);
                st.insert(path2);
                answer += 1;
                prev_i = next_i;
                prev_j = next_j;
            }
        } else if (dir == 'U'){
            t_i = prev_i;
            t_j = prev_j + 1;
            if (t_i > 5 || t_i < -5 || t_j > 5 || t_j < -5) continue;
            next_i = t_i;
            next_j = t_j;
            string path1 = to_string(prev_i) + to_string(prev_j) + to_string(next_i) + to_string(next_j);
            string path2 = to_string(next_i) + to_string(next_j) + to_string(prev_i) + to_string(prev_j);
            if (st.count(path1) || st.count(path2)){
                prev_i = next_i;
                prev_j = next_j;
            } else {
                st.insert(path1);
                st.insert(path2);
                answer += 1;
                prev_i = next_i;
                prev_j = next_j;
            }
        } else {
            t_i = prev_i;
            t_j = prev_j - 1;
            if (t_i > 5 || t_i < -5 || t_j > 5 || t_j < -5) continue;
            next_i = t_i;
            next_j = t_j;
            string path1 = to_string(prev_i) + to_string(prev_j) + to_string(next_i) + to_string(next_j);
            string path2 = to_string(next_i) + to_string(next_j) + to_string(prev_i) + to_string(prev_j);
            if (st.count(path1) || st.count(path2)){
                prev_i = next_i;
                prev_j = next_j;
            } else {
                st.insert(path1);
                st.insert(path2);
                answer += 1;
                prev_i = next_i;
                prev_j = next_j;
            }
        }
    }
    return answer;
}