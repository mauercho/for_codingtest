import sys
input = sys.stdin.readline

from collections import deque

def bfs():
    flag = False
    global ans
    q = deque()
    q.append((N, 0, ""))
    visited[N] = True
    while q:
        x, cnt, move = q.popleft()
        visited[x] = True
        if x == K:
            if not flag:
                ans = cnt
                flag = True
            if move not in move_set:
                move_set.add(move)
        if flag and cnt != ans:
            return
        if 0 <= x - 1 <= 100000 and not visited[x - 1]:
            q.append((x - 1,cnt + 1, move + "D"))
        if 0 <= x + 1 <= 100000 and not visited[x + 1]:
            q.append((x + 1, cnt + 1, move + "U"))
        if x != 0 and 2 * x <= 100000 and not visited[2 * x]:
            q.append((2 * x, cnt + 1, move + "M"))

move_set = set()
ans = 0
N, K = map(int, input().split())
visited = [False] * 100001
bfs()
print(ans)
print(len(move_set))