import sys
from collections import deque

input = sys.stdin.readline



for tc in range(int(input())):
    n = int(input())
    indegree = [0] * (n + 1)
    graph = [[False] * (n + 1) for _ in range(n + 1)]
    lst = list(map(int, input().split()))
    for i in range(n):
        for j in range(i + 1, n):
            indegree[lst[j]] += 1 # i 가 순위가 더 높음. j
            graph[lst[i]][lst[j]] = True # 앞에 것이 더 순위가 더 높음.
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if graph[a][b]: # a가 더 순위가 더 높으면 -> 이제 낮아져야 함. 낮은 놈은 indegree 증가
            graph[a][b] = False
            graph[b][a] = True
            indegree[b] -= 1
            indegree[a] += 1
        else: # b가 더 순위가 높음
            graph[b][a] = False
            graph[a][b] = True
            indegree[a] -= 1
            indegree[b] += 1
    q = deque()
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)
    cycle = False
    concern = False
    result = []
    for _ in range(n):
        if len(q) == 0:
            cycle = True
            break
        if len(q) >= 2:
            concern = True
            break
        now = q.popleft()
        result.append(now)
        for idx in range(1, n + 1):
            if graph[now][idx]:
                indegree[idx] -= 1
                if indegree[idx] == 0:
                    q.append(idx)

    if cycle:
        print("IMPOSSIBLE")
    elif concern:
        print("?")
    else:
        print(*result)

