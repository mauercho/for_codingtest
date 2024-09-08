#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<int> idxes;
int chicken_num;
int result = 10001;

int get_distance(int z, int x, int c, int v)
{
    return (max(z, c) - min(z, c)) + (max(x, v) - min(x, v));
}

void calculate(vector<int> idxes)
{
    int ret = 0;
    int dist;
    int a, b;
    for (auto mem : houses) {
        dist = 1000;
        for (int i = 0; i < M; i++)
        {
            tie(a, b) = chickens[idxes[i]];
            dist = min(dist, get_distance(mem.first, mem.second, a, b));
        }
        ret += dist;
    }
    result = min(result, ret);
}

void combi(int start, vector<int> idxes)
{
    if (idxes.size() == M)
    {
        calculate(idxes);
        return;
    }
    for (int i = start + 1; i < chicken_num; i++)
    {
        idxes.push_back(i);
        combi(i, idxes);
        idxes.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                houses.push_back({ i, j });
            }
            else if (arr[i][j] == 2)
            {
                chickens.push_back({ i, j });
                chicken_num++;
            }
        }
    }
    combi(-1, idxes);
    cout << result;
    return 0;
}