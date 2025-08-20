#include <iostream>
#include <map>
#include <queue>

using namespace std;


int mA, mB; // max a b
int cA, cB; // current a  b
int fA, fB; // final a b
int answer = -1;
map<pair<int, int>, int> visited; // 이걸로 배열 대체 할거임.

void bfs(){
	queue<pair<int, int> > q;
	visited[{0, 0}] = 0;
	q.push({0, 0});
	while (!q.empty()){
		tie(cA, cB) = q.front();
		if (cA == fA && cB == fB){
			answer = visited[{cA, cB}];
			return ;
		}
		q.pop();
		// fill 하기
		if (visited.count({mA, cB}) == 0){
			visited[{mA, cB}] = visited[{cA, cB}] + 1;
			q.push({mA, cB});
		}
		if (visited.count({cA, mB}) == 0){
			visited[{cA, mB}] = visited[{cA, cB}] + 1;
			q.push({cA, mB});
		}
		if (visited.count({0, cB}) == 0){
			visited[{0, cB}]= visited[{cA, cB}] + 1;
			q.push({0, cB});
		}
		if (visited.count({cA, 0}) == 0){
			visited[{cA, 0}]= visited[{cA, cB}] + 1;
			q.push({cA, 0});
		}
		// 여기서 a랑 b랑 옮기는건데.

		if (cA + cB <= mB){
			if (visited.count({0, cA + cB}) == 0){
				visited[{0, cA + cB}] = visited[{cA, cB}] + 1;
				q.push({0, cA + cB});
			}
		} else{
			if (visited.count({cA + cB - mB, mB}) == 0){
				visited[{cA + cB - mB, mB}] = visited[{cA, cB}] + 1;
				q.push({cA + cB - mB, mB});
			}
		}
		if (cA + cB <= mA){
			if (visited.count({cA + cB, 0}) == 0){
				visited[{cA + cB, 0}] = visited[{cA, cB}] + 1;
				q.push({cA + cB, 0});
			}
		} else {
			if (visited.count({mA, cA + cB - mA}) == 0){
				visited[{mA, cA + cB - mA}] = visited[{cA, cB}] + 1;
				q.push({mA, cA + cB - mA});
			}
		}
	}
}

int main(){
	cin >> mA >> mB >> fA >> fB;
	bfs();
	cout << answer;
	return 0;
}
